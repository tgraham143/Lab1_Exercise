// Lab 1.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int choice = 0;

	string name = "";

	/* Age was changed from a string to an int below.
	It caused problems when trying to increment "age" because it was a string.
	Changing "age" to an int allowed it to be incremented. */
	//string age = "";
	int age = -1;

	string occup = "";

	while (choice != -1)
	{
		cout << "\n-1: Exit\n";
		cout << "1: Enter Name\n";
		cout << "2: Enter Age\n";
		cout << "3: Enter Occupation\n";
		cin >> choice;


		switch (choice)
		{
			/* Handled the valid "-1" as an input option. */
		case -1:
			break;
		case 1:
			cout << "What is your Name: ";
			/* Opted to not use "cin" since it only reads in the data up to
			the first whitespace character. This left data in the input
			stream that caused problems later if we typed in more than
			one name. */
			//cin >> name;

			/* Cleared the input stream through the '\n' character and read
			the subsequent data and placed it in "name".
			Found the solution in Chapter 8, though the random 1000
			characters maximum to skip seems arbitrary. */
			cin.ignore(1000, '\n');
			getline(cin, name);
			break;
		case 2:
			cout << "What is your Age? ";
			cin >> age;

			/* If we entered non-numeric data for age it failed. For data
			validation, we checked the failbit flag on the input
			stream to see if it was set. If so, we return a message to the 
			user, clear the failbit flag, clear the input stream, and set
			"age" back to -1. */
			if (cin.fail()) {
				cout << "Invalid Age value.\n";
				cin.clear();
				cin.ignore(1000, '\n');
				age = -1;
			}

			/* In case multiple values were entered, we cleared the input
			stream through the '\n' character. Found the solution in
			Chapter 8, though the random 1000 characters maximum to skip
			seems arbitrary. */
			cin.ignore(1000, '\n');
			break;
		case 3:
			cout << "What is your Occupation? ";
			/* Opted to not use "cin" since it only reads in the data up to
			the first whitespace character. This left data in the input
			stream that caused problems later if we typed in multiple words. */
			//cin >> occup;

			/* Cleared the input stream through the '\n' character and read
			the subsequent data and placed it in "occup".
			Found the solution in Chapter 8, though the random 1000
			characters maximum to skip seems arbitrary. */
			cin.ignore(1000, '\n');
			getline(cin, occup);
			break;
		default:
			// Assume Invalid Menu Choice
			cout << "Sorry that choice is not valid!\n";

			/* If we entered non-numeric data for our menu option it failed.
			For data validation, we checked the failbit flag on the input
			stream to see if it was set. If so, we clear the failbit flag. */
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			break;
		}
	}

	age += 1;

	cout << "\nThank you for using our application, " << name << ", and hope your career in " << occup << " is successful.";
	cout << " Hope your " << age << " birthday will be enjoyable and exciting.";

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
