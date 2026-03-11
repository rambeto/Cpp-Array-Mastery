#include <iostream>   // For input/output operations
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()
using std::cin;
using std::cout;
using std::endl;

// Maximum size of the array
const int MAX_SIZE = 100;

/**
 * @brief Generates a random integer within the inclusive range [From, To]
 * 
 * @param From The lower bound of the range
 * @param To The upper bound of the range
 * @return int A random number between From and To
 */
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

/**
 * @brief Fills an array with random integers between 1 and 100
 * 
 * Prompts the user to enter the number of elements to generate,
 * then fills the array with random integers.
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
 * @brief Calculates the sum of all elements in the array
 * 
 * @param arr Array of integers
 * @param arrLength Number of elements in the array
 * @return int The sum of all elements
 */
int SumArray(const int arr[], int arrLength)
{
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
        sum += arr[i];
    return sum;
}

/**
 * @brief Main function: Program entry point
 */
int main()
{
    srand(static_cast<unsigned>(time(nullptr))); // Seed random number generator

    int arr[MAX_SIZE];   // Array to store integers
    int arrLength;       // Number of elements to fill

    // Fill the array with random numbers
    FillArrayWithRandomNumbers(arr, arrLength);

    // Display the array elements
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Calculate and display the sum of all numbers
    cout << "\nSum of all numbers: " << SumArray(arr, arrLength) << endl;

    return 0;  // Successful execution
}
