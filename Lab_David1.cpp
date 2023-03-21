#include <iostream>
#include "pch.h"
#include "framework.h"
#include "Lab_David1.h"
#include <Windows.h>
#include <cmath>
#include <unordered_map>
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
 
void inputArray(int* arr, int n) // вводить масив arr довжиною n елементів
{
    for (int i = 0; i < n; i++) // проходимося циклом по кожному елементу масиву
    {
        cout << "Enter element " << i + 1 << ": "; // виводимо на екран індекс елементу
        cin >> arr[i]; // зчитуємо з консолі значення елементу і записуємо його в масив
    }
}

void readArray(int arr[], int size) // читає масив arr довжиною size
{
	for (int i = 0; i < size; i++) // проходимося циклом по кожному елементу масиву
	{
		cin >> arr[i]; // зчитуємо з консолі значення елементу і записуємо його в масив
	}
}

void printArray(int arr[], int size) // виводить масив arr довжиною size
{
	for (int i = 0; i < size; i++) // проходимося циклом по кожному елементу масиву
	{
		cout <<  arr[i] << " "; // виводимо значення елементу на екран
	}
	cout << endl;
}

//Задано одновимірні масиви А і В розміру N. Всі додатні елементи масиву А замінити
//елементами з відповідними індексами масиву В.

void replacePositiveElements(int arrA[], int arrB[], int size) //приймає три аргументи: arrA і arrB, обидва є цілочисельними масивами, і size, цілочисельне значення, яке являє собою розмір обох масивів.
{
    for (int i = 0; i < size; i++) // проходимося циклом по кожному елементу масиву
    {
        if (arrA[i] > 0);  // якщо значення елементу більше 0, то ми не робимо з ним нічого
        {
            arrA[i] = arrB[i]; // якщо значення елементу менше або дорівнює 0, то замінюємо його на відповідний елемент з масиву B
        }
    }
}

void firstTask()
{
    int N;
    cout << "Enter the size of the arrays -> ";
    cin >> N;
    int* A = new int[N];
    int* B = new int[N];
    
    cout << "Enter elements of array A: ";
        readArray(A, N);

    cout << "Enter elements of array B: ";
        readArray(B, N);

    cout << "Initial Array A: ";
        printArray(A, N);

    cout << "Initial Array B: ";
        printArray(B, N);
    cout << endl;

    replacePositiveElements(A, B, N);

    cout << "Array A after replacement: ";
        printArray(A, N);

    delete[] A;
    delete[] B;

}

//Знайти номер першого мінімального елемента серед елементів, більших Т1 і
//розташованих правіше першого елемента, рівного Т2.

void findMinIndex(int arr[], int n, int T1, int T2)
{
    int minIndex = -1; // початково значення індексу мінімального елементу встановлено на -1
    for (int i = 0; i < n; i++) { // перебираємо всі елементи масиву в циклі
        if (arr[i] > T1 && arr[i] == T2) { // перевірка на виконання двох умов
            for (int j = i + 1; j < n; j++) { // якщо умови виконані, шукаємо мінімальний елемент у решті масиву
                if (minIndex == -1 || arr[j] < arr[minIndex]) { // перевірка, чи елемент є мінімальним
                    minIndex = j; // якщо так, зберігаємо його індекс
                }
            }
            break; //вихід з циклу, якщо знайдено мінімальний елемент
        }
    }
    if (minIndex == -1) { // якщо мінімальний елемент не знайдено, виводимо відповідне повідомлення
        cout << "No element found." << endl;
    }
    else { // якщо мінімальний елемент знайдено, виводимо його індекс
        cout << "Index of first minimum element: " << minIndex << endl;
    }
    
}

void secondTask()
{
    int n, T1, T2;
    
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n]; // оголошення масиву "arr" розміром "n" елементів

    inputArray(arr, n);

    cout << "Enter T1: ";
    cin >> T1;
    cout << "Enter T2: ";
    cin >> T2;

    findMinIndex(arr, n, T1, T2); 
    /*виклик функції "findMinIndex" для знаходження індексу мінімального елементу в масиві "arr",
    який більший або рівний "T1" і менший або рівний "T2"*/ 

    delete[] arr;
}

//Задано масив цілих чисел A(n), n <= 400
//Розробити програму, яка знаходить максимальне серед тих чисел, які не повторюються.

void ThirdTaskReadArray(vector<int>& arr)
{
    int n;
    cout << "Enter the number of integers: "; // Вивід повідомлення про введення кількості цілих чисел
    cin >> n; // Зміна розміру масиву на введену кількість
    arr.resize(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) { // Зчитування чисел масиву з клавіатури
        cin >> arr[i];
    }
}

void findMaxNonRepeated(const vector<int>& arr) // Функція для знаходження максимального неповторюваного числа в масиві
{
    unordered_map<int, int> count; // Створення хеш-таблиці для підрахунку кількості входжень чисел у масив
    for (int x : arr) // Підрахунок кількості входжень кожного числа в масив
    {
        count[x]++;
    }
    int maxNonRepeated = -1; // Ініціалізація змінної для збереження максимального неповторюваного числа
    for (int x : arr) { // Пошук максимального неповторюваного числа у масиві
        if (count[x] == 1 && x > maxNonRepeated) {
            maxNonRepeated = x;
        }
    }
    if (maxNonRepeated != -1) {
        cout << "Max non-repeated number: " << maxNonRepeated << endl;
    }
    else {
        cout << "There are no non-repeated numbers." << endl;
    }
}

void thirdTask() // Оголошення та ініціалізація масиву
{
    vector<int> arr; // Оголошення та ініціалізація масиву
    ThirdTaskReadArray(arr); // Зчитування масиву з клавіатури 
    findMaxNonRepeated(arr); // Знаходження максимального неповторюваного числа в масиві
}


//Основне меню вибору програми.

int main()
{
int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    flag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(flag);
    while (true)
    {
        int input;
        cout << "MAIN MENU: " << endl;
        cout << "1. firstTask" << endl;
        cout << "2. secondTask" << endl;
        cout << "3. thirdTask" << endl;
        cout << "4. EXIT" << endl;
        cout << "Selection: ";
        cin >> input;
        system("cls");
        switch (input) {
        case 1:
            firstTask();
            system("pause");
            system("cls");
            break;
        case 2:
            secondTask();
            system("pause");
            system("cls");
            break;
        case 3:
            thirdTask();
            system("pause");
            system("cls");
            break;
        case 4:
            return 0;
        default:
            MessageBox(NULL, L"Incorrect value.", L"!!!ERROR!!!", MB_ICONERROR);
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}