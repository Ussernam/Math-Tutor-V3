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
using namespace std;

int main() {
    string userName = "";
    int leftNum = 1;
    int rightNum = 1;
    int mathType = 1;
    char mathSymbol;
    int correctAnswer = 0;
    int userAnswer = 0;
    int temp = 0;
    const int MAX_ATTEMPTS = 3;
    const int LEVEL_RANGE_CHANGE = 10;
    string continueOption = "?";
    bool isCorrect = false;

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
    cin >> userName;

    // Greet the user
    cout << "Welcome " << userName << " to the Silly Simple Math Tutor!" << endl << endl;

    // Main quiz loop
    do {
        // Generate random problem
        leftNum = rand() %10 + 1;
        rightNum = rand() %10 + 1;
        mathType = rand() %4 + 1;

        switch (mathType) {
            case 1: // Addition
                correctAnswer = leftNum + rightNum;
            mathSymbol = '+';
            break;
            case 2: // Subtraction
                if (rightNum > leftNum) {
                    temp = leftNum;
                    leftNum = rightNum;
                    rightNum = temp;
                }
            correctAnswer = leftNum - rightNum;
            mathSymbol = '-';
            break;
            case 3: // Multiplication
                correctAnswer = leftNum * rightNum;
            mathSymbol = '*';
            break;
            case 4: // Division
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
            cout << leftNum << " " << mathSymbol << " " << rightNum << " = ";
            cin >> userAnswer;

            if (userAnswer == correctAnswer) {
                cout << "Congratulations, " << userName << "! That is the correct answer!" << endl << endl;
                isCorrect = true;
                break; // break out of the attempts loop
            } else {
                if (attempt < MAX_ATTEMPTS) {
                    cout << "Sorry, that is incorrect!" << endl;
                    cout << "You have " << (MAX_ATTEMPTS - attempt) << " attempts remaining." << endl << endl;
                } else {
                    cout << "Sorry, that is incorrect!" << endl;
                    cout << "No attempts remaining. The correct answer was: " << correctAnswer << endl;
                    cout << "Game over!" << endl;
                    // Exit the program immediately
                    return 0;
                }
            }
        }

        // Ask to continue only if the answer was correct
        cout << "Do you want to continue (y=yes | n=no)? ";
        cin >> continueOption;
        cout << endl;
    } while (continueOption == "y" || continueOption == "yes");
    // Exit message
    cout << "Sorry, this is all the program does for this moment." << endl;
    cout << "Version 4 is coming soon..." << endl;
    cout << "End of program." << endl;

    return 0;
}
