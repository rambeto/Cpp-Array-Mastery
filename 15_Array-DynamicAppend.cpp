#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify code.

// ========================================
// Function: ReadNumber
// Purpose: Prompts the user to enter a number.
// Returns:
//   - The number entered by the user.
// ========================================
int ReadNumber()
{
    int Number;

    cout << "\nPlease enter a number? ";
    cin >> Number;

    return Number;
}

// ========================================
// Function: AddArrayElement
// Purpose: Adds a new element to the array.
// Parameters:
//   - Number    : The number to be added.
//   - arr       : The destination array.
//   - arrLength : Reference to the current array length.
// Behavior:
//   - Increases the array length.
//   - Stores the new element at the last position.
// ========================================
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    arrLength++;
}

// ========================================
// Function: InputUserNumbersInArray
// Purpose: Allows the user to input numbers into an array
//          until they choose to stop.
// Parameters:
//   - arr       : The array where numbers will be stored.
//   - arrLength : Reference to the current array length.
// ========================================
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;

    do
    {
        AddArrayElement(ReadNumber(), arr, arrLength);

        cout << "\nDo you want to add more numbers? [0]:No, [1]:Yes? ";
        cin >> AddMore;

    } while (AddMore);
}

// ========================================
// Function: PrintArray
// Purpose: Prints all elements of the array.
// Parameters:
//   - arr       : The array to print.
//   - arrLength : Number of elements in the array.
// ========================================
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << endl;
}

// ========================================
// Main Function
// Purpose: Demonstrates how to dynamically add elements
//          to an array and then print the result.
// ========================================
int main()
{
    int arr[100];
    int arrLength = 0;

    // Allow the user to input numbers
    InputUserNumbersInArray(arr, arrLength);

    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";

    PrintArray(arr, arrLength);

    return 0;
}
