//------------------------------------------------------------
// Purpose: Program that encodes and/or decodes messages using two variations of "Caesar cipher" algorithm 
// Author: Corey Rodgers
//
//------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
    //Local variable declarations
    int choice, i;
    int shift = 3;
    char input[100];

    //Introduce the cipher
    cout << "Welcome to Corey's Caesar cipher" << endl;

    //Allow user to choose to encrypt or decrypt 
    cout << "Would you like to 1. encode or 2. decode: ";
    cin >> choice;

    if (choice == 1)
    {
        char ch = ' ';
        cout << "Enter message followed by a period on a seperate line with no spaces: " << endl;
        cin.getline(input, 100);

        for (i = 0; input[i] != '\0'; i++)
        {
            ch = input[i];
            if (isupper(input[i]))
            {
                ch = ch + shift;
            }
            if (islower(input[i]))
            {
                ch = ch - 'z' + 'a' - 1;
            }
            input[i] = ch;
        }
    }
    cout << input;

/*    if (choice == 2)
    {
        cout << "Enter message followed by a period on a seperate line with no spaces: " << endl;
        cin >> input;
        while (input < 'a' && input < 'z')
        {
            for (int i = 0; i < input; i++)
                output += ((input + shift + 65) % 26);
        }
    }

    cout << output;



    cout << output;
    */
}