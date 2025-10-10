/*
 * Program......: Math Tutor V3
 * Programmers..: Dylan Frohberg, Sean Lee
 * Date.........: 2025.10.10
 * Github Repo..: https://github.com/Ussernam/Math-Tutor-V3.git
 * Description..: An math tutor with a leveling system and while loop to give the user multiple questions.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cctype>
using namespace std;

int main() {

    //Constant Variables (These do not change throughout the program)
    const int MAX_ATTEMPTS = 3;
    const int LEVEL_RANGE_CHANGE = 10;

    // MathType enum to specify the operator instead of just a number
    enum MathType {ADD = 1, SUBTRACT = 2, MULTIPLY = 3, DIVIDE = 4};
    MathType mathType = ADD;

    string userName = "";
    string continueOption = "?";

    char mathSymbol = ' ';

    int leftNum = 1;
    int rightNum = 1;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;
    int currentRange = 10;
    int correctAnswer = 0;
    int userAnswer = 0;
    int temp = 0;

    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    // Opening ASCII and welcome message
    cout << " __  __       _   _       _____      _" << endl;
    cout << "|  \\/  | __ _| |_| |__   |_   _|   _| |_ ___  _ __" << endl;
    cout << "| |\\/| |/ _` | __| '_ \\    | || | | | __/ _ \\| '__|" << endl;
    cout << "| |  | | (_| | |_| | | |   | || |_| | || (_) | |" << endl;
    cout << "|_|  |_|\\__,_|\\__|_| |_|   |_| \\__,_|\\__\\___/|_|" << endl;

    cout << "********************************************************************************************************" << endl;
    cout << "*                          Welcome to the Silly Simple Math Tutor                                      *" << endl;
    cout << "********************************************************************************************************" << endl;
    cout << "Fun Math Facts " << endl;
    cout << "* Math teachers have problems. " << endl;
    cout << "* Math is the only subject that counts. " << endl;
    cout << "* If it seems easy, you're doing it wrong. " << endl;
    cout << "* It's all fun and games until someone divides by zero! " << endl;
    cout << "*******************************************************************************************************" << endl;

    // Ask user for their name
    cout << "\nWhat is your name? ";
    getline(cin, userName);

    // Greet the user
    cout << "Welcome " << userName << " to the Silly Simple Math Tutor!" << endl << endl;

    // Main quiz loop
    do {
        // Generate random problem
        leftNum = rand() % currentRange + 1;
        rightNum = rand() % currentRange + 1;

        // Cast a random number 1 - 4 and translate the number to the appropriate mathType.
        mathType = static_cast<MathType>(rand() %4 + 1);

        switch (mathType) {

            case ADD: // Addition
                correctAnswer = leftNum + rightNum;
                mathSymbol = '+';
            break;

            case SUBTRACT: // Subtraction
                // Switch around the numbers if the right number is greater than the left (dodges negative answer)
                if (rightNum > leftNum) {
                    temp = leftNum;
                    leftNum = rightNum;
                    rightNum = temp;
                }
                correctAnswer = leftNum - rightNum;
                mathSymbol = '-';
            break;

            case MULTIPLY: // Multiplication
                correctAnswer = leftNum * rightNum;
                mathSymbol = '*';
            break;

            case DIVIDE: // Division
                // Assign correct answer to the left number and multiply it by the right to guarantee the answer is a whole number
                correctAnswer = leftNum;
                leftNum *= rightNum;
                mathSymbol = '/';
            break;

            default: // If the mathType is not specified correctly, there is an error in the program.
                cout << "Incorrect math type: " << mathType << endl;
                cout << "Program ended with error code -1" << endl;
                cout << "Please report this error to Sean Lee" << endl;
                exit(-1);
        }

        // This for loop is used to give the user the question, and provide 3 attempts to answer the question.
        for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {

            // Provide the question to the user
            cout << "[Level #" << mathLevel << "] " << userName << ", what does " << leftNum << " " << mathSymbol << " " << rightNum << " = ";

            // Loop until the user enters numeric data
            while (!(cin >> userAnswer)) {
                cin.clear(); // Clear the cin error flag
                // need to include the limits library to use numeric_limits
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the max input, up to a new line
                cout << "\tInvalid input!" << endl;
                cout << "\tPlease enter a number: "; // end of get userAnswer while loop
            }

            // Correct answer
            if (userAnswer == correctAnswer) {
                totalCorrect++;
                cout << "Congratulations, " << userName << "! That is the correct answer!" << endl << endl;
                break; // break out of the attempts loop

            } else {
                // If answer is incorrect, and they still have attempts left, display the attempts remaining
                if (attempt < MAX_ATTEMPTS) {
                    totalIncorrect++;
                    cout << "Sorry, that is incorrect!" << endl;
                    cout << "You have " << (MAX_ATTEMPTS - attempt) << " attempts remaining." << endl << endl;
                }
                // If the answer is incorrect, and they have no more attempts, display the correct answer
                else {
                    totalIncorrect++;
                    cout << "Sorry, that is incorrect!" << endl;
                    cout << "No attempts remaining. The correct answer was: " << correctAnswer << endl;
                }

            }
        }

        // If they get 3 correct, level them up
        if (totalCorrect == 3) {
            mathLevel++;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange = currentRange + LEVEL_RANGE_CHANGE; // Increment the range by the constant LEVEL_RANGE_CHANGE
            cout << "You leveled up! Your are now level " << mathLevel << " and your new range is " << currentRange << "." << endl;
        }

        // If they get 3 incorrect and their math level is greater than 1, drop their level
        else if (totalIncorrect == 3 && mathLevel > 1) {
            mathLevel--;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange = currentRange - LEVEL_RANGE_CHANGE; // Decrement the range by the constant LEVEL_RANGE_CHANGE
            cout << "You dropped a level! Your are now level " << mathLevel << " and your new range is " << currentRange << "." << endl;
        }

        getline(cin, continueOption); // Clear output buffer

        // While loop to give them the option to do another question
        while (true) {
            cout << "Do you want to continue (y-yes | n-no)? ";
            getline(cin, continueOption);

            // to lower case the user's input by looping through each character and use the tolower function
            for (int i = 0; i < continueOption.size(); i++) {
                continueOption.at(i) = tolower(continueOption.at(i));
            }

            // If their response is valid, break the while loop
            if (continueOption == "y" || continueOption == "yes" || continueOption == "n" || continueOption == "no") {
                break;
            }

            // If their response is invalid, it will provide the "Do you want to continue" question again
            else {
                cout << "Invalid input, please try again.." << endl;
                cout << endl;
            } // end of if (y, yes, n, no)

        }
    }
    // While the continueOption, which was given the user's value in the while (true) loop, is y or yes, run the do again.
    while (continueOption == "y" || continueOption == "yes");

    // Exit message
    cout << "Goodbye!" << endl;
    cout << "Version 4 is coming soon..." << endl;
    cout << "End of program." << endl;

    return 0;
}
