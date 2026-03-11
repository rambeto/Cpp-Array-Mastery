#include <iostream>
using namespace std;

// Generate random number between From and To
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Fill array using pointers
void FillArrayWithRandomNumbers(int* arr, int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int* p = arr; p < arr + arrLength; p++)
        *p = RandomNumber(1, 100);
}

// Print array using pointers
void PrintArray(int* arr, int arrLength)
{
    for (int* p = arr; p < arr + arrLength; p++)
        cout << *p << " ";
    cout << "\n";
}

// Copy array in reverse using pointers
void CopyArrayInReverseOrder(int* src, int* dest, int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        *(dest + i) = *(src + arrLength - 1 - i);
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];
    CopyArrayInReverseOrder(arr, arr2, arrLength);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 elements after reverse copy:\n";
    PrintArray(arr2, arrLength);

    return 0;
}
