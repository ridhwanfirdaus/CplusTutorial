//
//  FactorialB.cpp
//  Write a program that estimates the value of the mathematical constant e.
//  Prompt the user for the desired accuracy of e
//
//  Created by Ekaba Ononse Bisong on 6/8/15.
//  Copyright (c) 2015 Ekaba Ononse Bisong. All rights reserved.
//

#include <iostream>
using namespace std;

// helper function prototypes
long double calculateE( int );   // function to calculate e
void clearInput();  // function to flush and reset cin
int readInt();      // function to read a non-negative integer
int calculateFactorial( int );  // function to calculate factorial

// main function to run program
int main()
{
    int run;    // hold variable to continue program
    
    do {
        // read a nonnegative integer
        int number = readInt();
        
        // print e
        cout << "e = " << calculateE(number);
        
        //continue program
        cout << "\n\nRun program again, 1 = Yes / 0 = No: ";
        cin >> run;
        
        // if running program again, print newline
        if (run == 1)
        {
            cout << endl;
        }
        
    } while (run == 1);
    
    return 0;
}

// function to flush and reset cin
void clearInput()
{
    cout << "ERROR: Wrong Input\n";
    cin.clear();                // take stream out of fail state
    cin.ignore(256, '\n');      // remove from the stream the input that caused the problem
}

// function to read a non-negative integer
// Note: Not a very robust check as more powerful techniques have not been taught
int readInt()
{
    bool loop = false;      // boolean variable to continue loop on wrong input
    int number = 0;         // return variable of non-negative integer
    
    do {
        int temp;           // variable to hold user-inputed number for checks
        cout << "Please enter a non-negative integer: ";
        cin >> temp;
        
        if (temp < 0)       // check if number entered is non-negative
        {
            clearInput();
            loop = true;
        } else if (temp == 0){  // check if number is zero
            loop = false;
        } else if(!(temp >> number)) {     // check if user entered a number
            clearInput();
            loop = true;
        }
        else {
            loop = false;
            number = temp;
        }
    } while (loop);
    
    return number;
}

// function to calculate factorial
int calculateFactorial( int n )
{
    int fact = 1;   // variable to hold factorial value
    
    // for loop to calculate factorial, n! = n * (n-1) * (n-2)....
    for (int i = n; i > 0; i--)
    {
        fact *= i;
    }
    
    return fact;
}

// function to calculate e
long double calculateE( int accuracy )
{
    long double e = 1.0f;  // variable holding value of e
    
    // for loop to calculate e
    for (int i = 1; i < accuracy; i++)
    {
        e += ( 1.0f / calculateFactorial(i) );
    }
    
    return e;
}