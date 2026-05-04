#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);

    //Initilize numbers and operators

    double numbers[100];
    char ops[100];
    int numCounter = 0, opCount = 0;

    string temp = "";
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (c == ' ') continue; // it will skip spces

        if ((c >= '0' && c <= '9') || c == '.') {
            temp += c;
        }
        else {
            
            if (temp != "") {
                numbers[numCounter++] = stod(temp); //Convert a string to double
                temp = "";
            }
          
            ops[opCount++] = c;
        }
    }
    if (temp != "") numbers[numCounter++] = stod(temp); // last number

    // multiplication and divison machine

    for (int i = 0; i < opCount; i++) {
        if (ops[i] == '*' || ops[i] == '/') {
            if (ops[i] == '*')
                numbers[i] = numbers[i] * numbers[i + 1];
            else
                numbers[i] = numbers[i] / numbers[i + 1];

            // shift numbers and ops left

            for (int j = i + 1; j < numCounter - 1; j++)
                numbers[j] = numbers[j + 1];
            for (int j = i; j < opCount - 1; j++)
                ops[j] = ops[j + 1];

            numCounter--;
            opCount--;
            i--; 
        }
    }

    // plus and minus machine

    double result = numbers[0];
    for (int i = 0; i < opCount; i++) {
        if (ops[i] == '+')
            result += numbers[i + 1];
        else if (ops[i] == '-')
            result -= numbers[i + 1];
    }

    cout << "Result: " << result << endl;
    return 0;
}