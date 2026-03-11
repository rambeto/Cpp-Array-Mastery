#include <iostream>   // For input/output operations
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()
using std::cin;
using std::cout;
using std::endl;

// Maximum size of the array
const int MAX_SIZE = 100;

/**
 * @brief Generates a random integer between two values (inclusive)
 * 
 * @param From The lower bound of the random range
 * @param To The upper bound of the random range
 * @return int A random number between From and To
 */
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

/**
 * @brief Fills an array with random numbers between 1 and 100
 * 
 * Prompts the user to enter the number of elements to generate,
 * then fills the array with random integers in the range [1, 100].
 * 
 * @param arr Array to store the random numbers
 * @param arrLength Reference variable to store the number of elements
 */
void FillArrayWithRandomNumbers(int arr[], int &arrLength)
{
    cout << "\nEnter number of elements: ";
    cin >> arrLength;

    if (arrLength > MAX_SIZE)
    {
        cout << "Number of elements exceeds MAX_SIZE (" << MAX_SIZE << "). Limiting to MAX_SIZE.\n";
        arrLength = MAX_SIZE;
    }

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
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
 * @brief Finds the minimum number in an array
 * 
 * @param arr Array of integers
 * @param arrLength Number of elements in the array
 * @return int The smallest number in the array
 */
int MinNumberInArray(const int arr[], int arrLength)
{
    int Min = arr[0];
    for (int i = 1; i < arrLength; i++)
    {
        if (arr[i] < Min)
            Min = arr[i];
    }
    return Min;
}

/**
 * @brief Main function: Program entry point
 */
int main()
{
    srand(static_cast<unsigned>(time(nullptr))); // Seed random number generator

    int arr[MAX_SIZE];   // Array to store up to MAX_SIZE integers
    int arrLength;       // Number of elements to fill

    // Fill array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    // Display array elements
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Display minimum number
    cout << "\nMin Number is: " << MinNumberInArray(arr, arrLength) << endl;

    return 0;
}
