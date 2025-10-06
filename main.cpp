/*
 *Program......: Math Tutor V3
 *Programmers..: Dylan Frohberg, Sean Lee
 *Date.........: 2025.22.9
 *Github Repo..: https://github.com/Ussernam/Math-Tutor-V3.git
 *Description..: An easy math tutor that lets the user know if their answer is correct or incorrect.
*/

#include <iostream>
#include <random>
#include <ctime>
#include <list>
using namespace std;

int main()
{
    string userName = "";
    int leftNum = 1;
    int rightNum = 1;
    int mathType = 1;
    char mathSymbol;
    int correctAnswer = 0;
    int userAnswer = 0;
    int temp = 0;

    srand(static_cast<unsigned int>(time(0)));

    //Opening to math tutor program
    cout << " __  __       _   _       _____      _" << endl;
    cout << "|  \\/  | __ _| |_| |__   |_   _|   _| |_ ___  _ __" << endl;
    cout << "| |\\/| |/ _` | __| '_ \\    | || | | | __/ _ \\| '__|" << endl;
    cout << "| |  | | (_| | |_| | | |   | || |_| | || (_) | |" << endl;
    cout << "|_|  |_|\\__,_|\\__|_| |_|   |_| \\__,_|\\__\\___/|_|" << endl;

    cout << "********************************************************************************************************" << endl;
    cout << "*                          Welcome to the Silly Simple Math Tutor                                      *" << endl;
    cout << "********************************************************************************************************" << endl;
    cout << "Fun Math Facts " << endl;
    cout << endl;
    cout << "* Math teachers have problems. " << endl;
    cout << "* Math is the only subject that counts. " << endl;
    cout << "* If it seems easy, you're doing it wrong. " << endl;
    cout << "* It's all fun and games until someone divides by zero! " << endl;
    cout << endl;
    cout << "*******************************************************************************************************" << endl;

    //asking user for their name
    cout << endl;
    cout << "What is your name? ";
    cin >> userName;

    //welcome user for input name
    cout << "Welcome ";
    cout << userName;
    cout << " to the Silly Simple Math Tutor!";
    cout << endl;

    //this is where a random number is generated
    leftNum = rand() %10 + 1;
    rightNum = rand() %10 + 1;
    mathType = rand() %4 + 1;

    //here a random operator is generated for the question to the user
    switch (mathType) {
        case 1: //addition
            correctAnswer = leftNum + rightNum;
            mathSymbol = '+';
            break;
        case 2: //subtraction
            if (rightNum > leftNum) {
                temp = leftNum;
                leftNum = rightNum;
                rightNum = temp;
            }
            correctAnswer = leftNum - rightNum;
            mathSymbol = '-';
            break;
        case 3: //subtraction
            correctAnswer = leftNum * rightNum;
            mathSymbol = '*';
            break;
        case 4: //division
            correctAnswer = leftNum;
            leftNum *= rightNum;
            mathSymbol = '/';
            break;
        default: //error handling
            cout << "Incorrect math type: " << mathType << endl;
            cout << "Program ended with error code -1" << endl;
            cout << "Please report this error to Sean Lee" << endl;
            exit(-1);
    }
    //outputs the question to the user
    cout << leftNum << " " << mathSymbol << " " << rightNum << " = ";
    cin >> userAnswer;

    //this tells the user if their answer was correct or incorrect
    if (userAnswer == correctAnswer) {
        cout << "Congratulations, " << userName << " that is the correct answer!" << endl;
        cout << endl;
    }
    else {
        cout << "Sorry, that is incorrect!" << endl;
        cout << "The correct answer is: " << correctAnswer << endl;
        cout << endl;
    }
    //programming closing message
    cout << "Sorry, this is all the program does for this moment. " << endl;
    cout << "Version 2 is coming soon... " << endl;
    cout << "End of program. " << endl;

    return 0;

}