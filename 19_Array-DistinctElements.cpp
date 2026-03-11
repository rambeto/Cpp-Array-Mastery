#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify code.

// ========================================
// Function: FillArray
// Purpose: Initializes the source array with predefined numbers
//          containing some duplicate values.
// Parameters:
//   - arr       : Source array.
//   - arrLength : Reference variable storing number of elements.
// ========================================
void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;

    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
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
// Function: FindNumberPositionInArray
// Purpose: Searches for a number in the array using Linear Search.
// Parameters:
//   - Number    : Value to search for.
//   - arr       : Array to search in.
//   - arrLength : Number of elements in the array.
// Returns:
//   - Index of the number if found.
//   - -1 if the number does not exist.
// ========================================
int FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;
    }

    return -1;
}

// ========================================
// Function: IsNumberInArray
// Purpose: Checks if a number exists in the array.
// Parameters:
//   - Number    : Value to search for.
//   - arr       : Array to search in.
//   - arrLength : Number of elements in the array.
// Returns:
//   - true  if the number exists.
//   - false otherwise.
// ========================================
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

// ========================================
// Function: AddArrayElement
// Purpose: Adds a new element to the end of the array.
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
// Function: CopyDistinctNumbersToArray
// Purpose: Copies only distinct numbers from the source array
//          into the destination array.
// Parameters:
//   - arrSource         : Source array.
//   - arrDestination    : Destination array.
//   - SourceLength      : Number of elements in source array.
//   - DestinationLength : Reference variable storing destination length.
// ========================================
void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
        {
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}

// ========================================
// Main Function
// Purpose: Demonstrates extracting distinct numbers
//          from an array into another array.
// ========================================
int main()
{
    int arrSource[100], SourceLength = 0;
    int arrDistinct[100], DistinctLength = 0;

    FillArray(arrSource, SourceLength);

    CopyDistinctNumbersToArray(arrSource, arrDistinct, SourceLength, DistinctLength);

    cout << "Source Array:\n";
    PrintArray(arrSource, SourceLength);

    cout << "\n---------------------------------------------\n";

    cout << "Distinct Numbers:\n";
    PrintArray(arrDistinct, DistinctLength);

    return 0;
}
