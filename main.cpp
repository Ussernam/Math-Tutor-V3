/*
 * Program......: Math Tutor V3
 * Programmers..: Dylan Frohberg, Sean Lee
 * Date.........: 2025.22.9
 * Github Repo..: https://github.com/Ussernam/Math-Tutor-V3.git
 * Description..: An easy math tutor that lets the user know if their answer is correct or incorrect.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cctype>
using namespace std;

int main() {
    const int MAX_ATTEMPTS = 3;
    const int LEVEL_RANGE_CHANGE = 10;

    enum MathType {ADD = 1, SUBTRACT = 2, MULTIPLY = 3, DIVIDE = 4};
    MathType mathType = ADD;

    string userName = "";
    int leftNum = 1;
    int rightNum = 1;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;
    int currentRange = 10;
    char mathSymbol = ' ';
    int correctAnswer = 0;
    int userAnswer = 0;
    int temp = 0;
    string continueOption = "?";

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
        mathType = static_cast<MathType>(rand() %4 + 1);

        switch (mathType) {
            case ADD: // Addition
                correctAnswer = leftNum + rightNum;
            mathSymbol = '+';
            break;
            case SUBTRACT: // Subtraction
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
                correctAnswer = leftNum;
            leftNum *= rightNum;
            mathSymbol = '/';
            break;
            default:
                cout << "Incorrect math type: " << mathType << endl;
            cout << "Program ended with error code -1" << endl;
            cout << "Please report this error to Sean Lee" << endl;
            exit(-1);
        }

        for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
            cout << "[Level #" << mathLevel << "] " << userName << ", what does " << leftNum << " " << mathSymbol << " " << rightNum << " = ";

            // Loop until the user enters numeric data
            while (!(cin >> userAnswer)) {
                cin.clear(); // Clear the cin error flag
                // need to include the limits library to use numeric_limits
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the max input, up to a new line
                cout << "\tInvalid input!" << endl;
                cout << "\tPlease enter a number: "; // end of get userAnswer while loop
            }


            if (userAnswer == correctAnswer) {
                totalCorrect++;
                cout << "Congratulations, " << userName << "! That is the correct answer!" << endl << endl;
                break; // break out of the attempts loop
            } else {
                if (attempt < MAX_ATTEMPTS) {
                    totalIncorrect++;
                    cout << "Sorry, that is incorrect!" << endl;
                    cout << "You have " << (MAX_ATTEMPTS - attempt) << " attempts remaining." << endl << endl;
                } else {
                    totalIncorrect++;
                    cout << "Sorry, that is incorrect!" << endl;
                    cout << "No attempts remaining. The correct answer was: " << correctAnswer << endl;
                }
            }
        }
        if (totalCorrect == 3) {
            mathLevel++;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange = currentRange + LEVEL_RANGE_CHANGE;
            cout << "You leveled up! Your are now level " << mathLevel << " and your new range is " << currentRange << "." << endl;
        }
        else if (totalIncorrect == 3 && mathLevel > 1) {
            mathLevel--;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange = currentRange - LEVEL_RANGE_CHANGE;
            cout << "You dropped a level! Your are now level " << mathLevel << " and your new range is " << currentRange << "." << endl;
        }
        getline(cin, continueOption);
        while (true) {
            cout << "Do you want to continue (y-yes | n-no)? ";
            getline(cin, continueOption);

            // to lower case the user's input
            for (int i = 0; i < continueOption.size(); i++) {
                continueOption.at(i) = tolower(continueOption.at(i));
            }
            if (continueOption == "y" || continueOption == "yes" || continueOption == "n" || continueOption == "no") {
                break;
            }
            else {
                cout << "Invalid input, please try again.." << endl;
                cout << endl;
            } // end of if (y, yes, n, no)
        }

    } while (continueOption == "y" || continueOption == "yes");

    // Exit message
    cout << "Sorry, this is all the program does for this moment." << endl;
    cout << "Version 4 is coming soon..." << endl;
    cout << "End of program." << endl;

    return 0;
}
