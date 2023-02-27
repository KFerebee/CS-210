// Name        : ClockProj1KendallFerebee.cpp
// Author      : Kendall Ferebee
// SNHU Class  : CS210
// Description : 12 and 24 hour clock in C++


#include "Header.h"

void display(hours_12_format h1, hours_24_format h2) //Clock display
{
	cout << "\t\t*************************\t\t";
	cout << "*************************\n";
	cout << "\t\t*\t12-Hour Clock\t*\t\t";
	cout << "*\t24-Hour Clock\t*\n";
	cout << "\t\t*\t" << setw(2) << setfill('0') << h1.hour << ":" << setw(2) << setfill('0') << h1.minute << ":" << setw(2) << setfill('0') << h1.seconds << " " << h1.meridian << "\t*\t\t";
	cout << "*\t" << setw(2) << setfill('0') << h2.hour << ":" << setw(2) << setfill('0') << h2.minute << ":" << setw(2) << setfill('0') << h2.seconds << "\t*\n";
	cout << "\t\t*************************\t\t";
	cout << "*************************\n";
}

int main()	// Menu for user interaction with input 4 extining the program 
{
	hours_12_format h1;
	hours_24_format h2;
	display(h1, h2);
	int choice = 0;
	while (choice != 4)
	{
		cout << "\n\n*************************\n";
		cout << "* 1 - Add One Hour\t*\n";
		cout << "* 2 - Add One Minute\t*\n";
		cout << "* 3 - Add One Second\t*\n";
		cout << "* 4 - Exit Program\t*\n";
		cout << "*************************\n";
		cin >> choice;
		switch (choice)
		{
		case 1: h1.add_hour(1);
			h2.add_hour(1);
			break;
		case 2: h1.add_minute(1);
			h2.add_minute(1);
			break;
		case 3: h1.add_seconds(1);
			h2.add_seconds(1);
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Unexpected Input Received. Please Enter A Valid Menu Item.\n"; // Invalid entry 
		}
		system("cls");
		display(h1, h2);
	}
}