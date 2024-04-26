/*
File name: CS112_A2_T3_S15,16_20230134_20230140_20230433.cpp

Purpose: This is a rational number calculator that is capable of taking two rational numbers and an operation to perform on them and displaying the result of the operation.

Authors:
Author 1: Dima Khaled Allam
Section number: S15,16

Author 2: Rawan Rushdy Fathy
Section number: S15,16

Author 3: Mo'men Mamdouh Mahmoud
Section number: S15,16

Emails:
Email of Author 1: dkh3462@gamil.com

Email of Author 2: rawanrushdy551@gmail.com

Email of Author 3: momenmamdouh122@gmail.com

IDs:
ID1: 20230134 - simplified the final result and handled the whole number

ID2: 20230140 - did the mathematical calculations

ID3: 20230433 - sliced the input string and handled the wrong inputs

*/


//PSEUDO-CODE FOR THE RATIONAL CALCULATOR
/*
 function fractionSimplification(numerator, denominator)
    x = numerator
    y = denominator
    while y is not 0 do
        temp = y
        y = x % y
        x = temp
    end while
    numerator = numerator / x
    denominator = denominator / x
end function

function main()
    print "Welcome to rational number calculator!"

    loop indefinitely
        print newline
        print "Please enter a rational number operation (or 'exit'):"
        print "NOTICE: You cannot enter zero in the denominator, and the operator can only be (+, -, *, or /)!!!"

        inputOperation = read input from user

        if inputOperation is equal to "exit" or "EXIT" or "Exit" then
            print "Thank you for using the rational number calculator."
            exit program
        end if

        regexPattern = "^[\\+\\-]?\\d+(?:\\/(?!\\s)[1-9]\\d*)?\\s[\\+\\-\\*\\/]\\s[\\+\\-]?\\d+(?:\\/(?!\\s)[1-9]\\d*)?$"

        if inputOperation matches regexPattern then
            create stringstream stringslice with inputOperation
            read num1, slash, den1 from stringslice
            if slash is '/' then
                read den1 from stringslice
            else
                den1 = 1
            end if
            read operator, num2, slash, den2 from stringslice
            if slash is '/' then
                read den2 from stringslice
            else
                den2 = 1
            end if

            switch operator
                case '+':
                    den3 = den1 * den2
                    num3 = (num1 * den2) + (num2 * den1)
                    call fractionSimplification(num3, den3)
                    print inputOperation + " = " + num3 + "/" + den3
                    break
                case '-':
                    den3 = den1 * den2
                    num3 = (num1 * den2) - (num2 * den1)
                    call fractionSimplification(num3, den3)
                    print inputOperation + " = " + num3 + "/" + den3
                    break
                case '*':
                    den3 = den1 * den2
                    num3 = num1 * num2
                    call fractionSimplification(num3, den3)
                    print inputOperation + " = " + num3 + "/" + den3
                    break
                case '/':
                    den3 = den1 * num2
                    num3 = num1 * den2
                    call fractionSimplification(num3, den3)
                    print inputOperation + " = " + num3 + "/" + den3
                    break
            end switch
        else
            print "Invalid input. Try again."
        end if
    end loop
end function

 */


#include <iostream>
#include <sstream>
#include <string>
#include <regex>
using namespace std;

// Function to simplify a fraction
void fractionSimplification(int& numerator, int& denominator) {
    int x = numerator;
    int y = denominator;
    // Calculate the greatest common divisor (GCD) using Euclid's algorithm
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    // Divide both numerator and denominator by their GCD
    numerator /= x;
    denominator /= x;
}


int main() {
    //welcome message
    cout << "Welcome to rational number calculator! \n";

    //loop till user enters exit
    while (true) {
        cout << "\n";
        //a message for what to enter as an input
        cout << "Please enter a rational number operations (or exit): \n";
        //a message for input instructions
        cout << "NOTICE that you cannot enter zero in the denominator and the operator can only be (+ or - or * or /)!!!\n";

        //getting the input as a string
        string inputOperation;
        getline(cin, inputOperation);

        //check if the user enters exit
        if (inputOperation == "exit" || inputOperation == "EXIT" || inputOperation == "Exit") {
            cout << "Thank you for using rational number calculator \n";
            return 0;
        }

        //regular expression to check that the input follows the instructions of the rational operation
        regex regexrule("^[\\+\\-]?[1-9]\\d*(?:\\/(?!\\s)[1-9]\\d*)?\\s[\\+\\-\\*\\/]\\s[\\+\\-]?[1-9]\\d*(?:\\/(?!\\s)[1-9]\\d*)?$");

        //do the calculations if the input is valid
        if (regex_match(inputOperation, regexrule)) {
            //slicing the input string
            istringstream stringslice(inputOperation);
            int num1, num2, den1, den2;
            char oprator, slash;

            // Reading the first rational number
            stringslice >> num1;
            if (stringslice.peek() == '/') { // Check if the next character is a slash
                stringslice >> slash;
                stringslice >> den1;
            } else { // If the next character is not a slash, the number is a whole number
                den1 = 1; // Denominator for whole number is always 1
            }

            // Reading the operator and the second rational number
            stringslice >> oprator;
            stringslice >> num2;
            if (stringslice.peek() == '/') { // Check if the next character is a slash
                stringslice >> slash;
                stringslice >> den2;
            } else { // If the next character is not a slash, the number is a whole number
                den2 = 1; // Denominator for whole number is always 1
            }

            // Calculating the result
            int num3, den3;
            switch (oprator) {

                //calculations if the operator is a plus sign
                case '+':
                    den3 = den1 * den2;
                    num3 = (num1 * den2) + (num2 * den1);
                    fractionSimplification(num3,den3);
                    cout << inputOperation << " = " << num3 << "/" << den3 << "\n";
                    break;

                //calculations if the operator is a minus sign
                case '-':
                    den3 = den1 * den2;
                    num3 = (num1 * den2) - (num2 * den1);
                    fractionSimplification(num3,den3);
                    cout << inputOperation << " = " << num3 << "/" << den3 << "\n";
                    break;

                //calculations if the operator is a multiplication sign
                case '*':
                    den3 = den1 * den2;
                    num3 = num1 * num2;
                    fractionSimplification(num3,den3);
                    cout << inputOperation << " = " << num3 << "/" << den3 << "\n";
                    break;

                //calculations if the operator is a division sign
                case '/':
                    den3 = den1 * num2;
                    num3 = num1 * den2;
                    fractionSimplification(num3,den3);
                    cout << inputOperation << " = " << num3 << "/" << den3 << "\n";
                    break;
            }

        //print invalid if the input doesn't follow the instructions
        } else {
            cout << "Invalid input. Try again\n";
        }
    }

    return 0;
}


