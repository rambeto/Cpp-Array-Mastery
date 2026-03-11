#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify code.

// ========================================
// Enum: enPrimeNotPrime
// Purpose: Represents the result of a prime number check.
// Values:
//   - Prime     : The number is prime.
//   - NotPrime  : The number is not prime.
// ========================================
enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

// ========================================
// Function: CheckPrime
// Purpose: Determines whether a given number is prime.
// Parameters:
//   - Number : The number to check.
// Returns:
//   - enPrimeNotPrime::Prime if the number is prime.
//   - enPrimeNotPrime::NotPrime otherwise.
// Note:
//   - This implementation checks divisibility from 2 to Number/2.
//   - For better performance, sqrt(Number) is usually used.
// ========================================
enPrimeNotPrime CheckPrime(int Number)
{
    int M = Number / 2;

    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
}

// ========================================
// Function: RandomNumber
// Purpose: Generates a random integer within the range [From, To].
// Parameters:
//   - From : Lower bound of the range.
//   - To   : Upper bound of the range.
// Returns:
//   - A random integer between From and To.
// ========================================
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// ========================================
// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with random numbers between 1 and 100.
// Parameters:
//   - arr       : Destination array.
//   - arrLength : Reference variable storing number of elements.
// ========================================
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// ========================================
// Function: PrintArray
// Purpose: Prints all elements of the array.
// Parameters:
//   - arr       : Array to print.
//   - arrLength : Number of elements in the array.
// ========================================
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << endl;
}

// ========================================
// Function: AddArrayElement
// Purpose: Adds a new element to the end of an array.
// Parameters:
//   - Number    : Value to add.
//   - arr       : Target array.
//   - arrLength : Reference to the current array length.
// ========================================
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    arrLength++;
}

// ========================================
// Function: CopyPrimeNumbers
// Purpose: Copies only prime numbers from a source array
//          into a destination array.
// Parameters:
//   - arrSource            : Source array.
//   - arrDestination       : Destination array.
//   - arrLength            : Number of elements in the source array.
//   - arrDestinationLength : Reference variable storing destination length.
// ========================================
void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
    }
}

// ========================================
// Main Function
// Purpose: Demonstrates extracting prime numbers
//          from an array into another array.
// ========================================
int main()
{
    srand((unsigned)time(NULL));  // Seed random number generator.

    int arr[100];
    int arrLength = 0;

    int arr2[100];
    int arr2Length = 0;

    // Fill the source array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    // Copy only prime numbers
    CopyPrimeNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 Prime numbers:\n";
    PrintArray(arr2, arr2Length);

    return 0;
}
