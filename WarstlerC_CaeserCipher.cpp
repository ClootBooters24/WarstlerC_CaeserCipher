// WarstlerC_CSCE2004_Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
using namespace std;

//Function to encrypt the text
string encrypt(string message, int shiftKey)
{
	string result = "";

	//Traverse the text
	for (int i = 0; i < message.length(); i++)
	{
		//Encrypt uppercase
		if (isupper(message[i]))
		{
			//Equation to convert characters ASCII
			result += char(int(message[i] + shiftKey - 65) % 26 + 65);
		}

		//Encrypt lowercase
		else if (islower(message[i]))
		{
			//Equation to convert characters ASCII
			result += char(int(message[i] + shiftKey - 97) % 26 + 97);
		}

		//Else to append a space into the message
		else
		{
			result.append(" ");
		}

		shiftKey++;
	}

	return result;
}

//Function to decrypt the text
string decrypt(string message, int shiftKey)
{
	string result = "";

	//Shift the key over 26 to recenter the combination
	shiftKey = 26 - shiftKey;

	//Traverse the text
	for (int i = 0; i < message.length(); i++)
	{
		//Dencrypt uppercase
		if (isupper(message[i]))
		{
			//Equation to convert characters ASCII
			result += char(int(message[i] + shiftKey - 65) % 26 + 65);
		}

		//Decrypt lowercase
		else if (islower(message[i]))
		{
			//Equation to convert characters ASCII
			result += char(int(message[i] + shiftKey - 97) % 26 + 97);
		}

		//Else to append a space into the message
		else
		{
			result.append(" ");
		}

		shiftKey = shiftKey - 1;
	}

	return result;
}


int main()
{
	string message;
	int shiftKey, choice;

	//Fix
	//String cannot have multiple lines

	//Take the message as input
	//Exit with -1
	cout << "Enter the message or leave blank to exit the program: ";
	getline(cin, message);


	//If -1, exit program
	if (message == "")
	{
		cout << "Exiting program...";
		return 0;
	}

	//Get the shift key
	cout << "Enter the key: ";
	cin >> shiftKey;

	//User chooses whether to encrypt or decrypt
	cout << "Enter your choice \n1. Encryption \n2. Decryption \n";
	cout << "Your choice: ";
	cin >> choice;

	if (choice == 1)
	{
		cout << "Cipher: " << encrypt(message, shiftKey);

	}

	else if (choice == 2)
	{
		cout << "Message: " << decrypt(message, shiftKey);
	}

	else
	{
		return 0;
	}
}