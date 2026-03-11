#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify code.

// ========================================
// Enumeration: enCharType
// Purpose: Defines character categories used for random character generation.
// Values:
//   - SmallLetter      : Lowercase letters (ASCII 97–122)
//   - CapitalLetter    : Uppercase letters (ASCII 65–90)
//   - SpecialCharacter : Special characters (ASCII 33–47)
//   - Digit            : Digits (ASCII 48–57)
// ========================================
enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

// ========================================
// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
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
// Function: GetRandomCharacter
// Purpose: Returns a random character based on the specified character type.
// Parameters:
//   - CharType : The type of character to generate.
// Returns:
//   - A random character from the selected category.
// ========================================
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case SmallLetter:
        return char(RandomNumber(97, 122));

    case CapitalLetter:
        return char(RandomNumber(65, 90));

    case SpecialCharacter:
        return char(RandomNumber(33, 47));

    case Digit:
        return char(RandomNumber(48, 57));
    }

    return '\0'; // Fallback in case of unexpected input
}

// ========================================
// Function: GenerateWord
// Purpose: Generates a random word consisting of characters of a specific type.
// Parameters:
//   - CharType : Character type to use.
//   - Length   : Number of characters in the word.
// Returns:
//   - A randomly generated string.
// ========================================
string GenerateWord(enCharType CharType, short Length)
{
    string Word = "";

    for (int i = 0; i < Length; i++)
        Word += GetRandomCharacter(CharType);

    return Word;
}

// ========================================
// Function: GenerateKey
// Purpose: Generates a key formatted as XXXX-XXXX-XXXX-XXXX
//          where each X is a random uppercase letter.
// Returns:
//   - A formatted key string.
// ========================================
string GenerateKey()
{
    return GenerateWord(CapitalLetter, 4) + "-" +
           GenerateWord(CapitalLetter, 4) + "-" +
           GenerateWord(CapitalLetter, 4) + "-" +
           GenerateWord(CapitalLetter, 4);
}

// ========================================
// Function: FillArrayWithKeys
// Purpose: Fills an array with randomly generated keys.
// Parameters:
//   - arr       : Destination string array.
//   - arrLength : Number of keys to generate.
// ========================================
void FillArrayWithKeys(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateKey();
}

// ========================================
// Function: PrintStringArray
// Purpose: Prints all elements of a string array with their indices.
// Parameters:
//   - arr       : The array to print.
//   - arrLength : Number of elements in the array.
// ========================================
void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\nGenerated Keys:\n\n";

    for (int i = 0; i < arrLength; i++)
        cout << "Array[" << i << "] : " << arr[i] << endl;

    cout << endl;
}

// ========================================
// Function: ReadPositiveNumber
// Purpose: Reads a positive integer from the user.
// Parameters:
//   - Message : Prompt message displayed to the user.
// Returns:
//   - A validated positive integer.
// ========================================
int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

// ========================================
// Main Function
// Purpose: Generates a list of random license keys and prints them.
// ========================================
int main()
{
    srand((unsigned)time(NULL)); // Seed random generator

    string arr[100];
    int arrLength = ReadPositiveNumber("How many keys do you want to generate?\n");

    FillArrayWithKeys(arr, arrLength);
    PrintStringArray(arr, arrLength);

    return 0;
}
