#include <iostream>   // For input/output operations
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time() to seed random numbers

using std::cin;
using std::cout;
using std::endl;

// Maximum size of the array
const int MAX_SIZE = 100;

/**
 * @brief Generates a random integer between two numbers (inclusive)
 * 
 * @param From Lower bound
 * @param To Upper bound
 * @return int Random number between From and To
 */
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

/**
 * @brief Fills an array with random numbers
 * 
 * @param arr Array to fill
 * @param arrLength Number of elements to fill (entered by user)
 */
void FillArrayWithRandomNumbers(int arr[], int& arrLength)
{
    cout << "\nEnter number of elements: ";
    cin >> arrLength;

    if (arrLength > MAX_SIZE)
        arrLength = MAX_SIZE;  // Limit array size to MAX_SIZE

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);  // Fill each element with a random number
    }
}

/**
 * @brief Prints the elements of an array
 * 
 * @param arr Array to print
 * @param arrLength Number of elements in the array
 */
void PrintArray(const int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/**
 * @brief Finds the maximum number in an array
 * 
 * @param arr Array of integers
 * @param arrLength Number of elements in the array
 * @return int Maximum number in the array
 */
int MaxNumberInArray(const int arr[], int arrLength)
{
    if (arrLength == 0)
        return 0;  // Return 0 if array is empty

    int max = arr[0];  // Start with the first element

    for (int i = 1; i < arrLength; i++)
    {
        if (arr[i] > max)
            max = arr[i];  // Update max if current element is larger
    }

    return max;
}

int main()
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    int arr[MAX_SIZE];   // Array to hold numbers
    int arrLength;       // Number of elements in the array

    // Fill the array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    // Print the array
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Find and print the maximum number
    int maxNumber = MaxNumberInArray(arr, arrLength);
    cout << "\nMax Number is: " << maxNumber << endl;

    return 0;
}
