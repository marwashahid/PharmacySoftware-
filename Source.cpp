#include<iostream>
#include<fstream>
#include<string>
#include "Header.h"
using namespace std;
int main()
{
	int choice;          //declaring variable 
	do {                                 //loop to print menu and calling functions
		system("color 30");
		system("cls");
		cout << "\t\t\t\t------------------------MENU-------------------------" << endl;
		cout << "\t\t\t-----------------------WELCOME TO NOBLE PHARMACY----------------------" << endl;
		cout << "\n______________________\n|    |                |\n";
		cout << "| 1. | Enter data     |\n" << "|____|________________|\n|    |                |\n";
		cout << "| 2. | Search data    |\n" << "|____|________________|\n|    |                |\n";
		cout << "| 3. | Delete data    |\n" << "|____|________________|\n|    |                |\n";
		cout << "| 4. | Display data   |\n" << "|____|________________|\n|    |                |\n";
		cout << "| 5. | Receipt        |\n" << "|____|________________|\n|    |                |\n";
		cout << "| 6. | Exit           |\n" << "|____|________________|\n\n";

		cout << "Enter your choice :  "; //Prompt the user for input
		cin >> choice;                      //storing input in variable 
		system("cls");                     // Clearing  the screen 
		cout << "\t\t\t\t------------------------MENU-------------------------" << endl;
		cout << "\t\t\t-----------------------WELCOME TO NOBLE PHARMACY----------------------" << endl;
		switch (choice)
		{
		case 1:
			enter();    //CALLING THE ENTRY FUNCTION
			cout << "Data Entered successfully";
			break;
		case 2:
			search();    //CALLING THE SEARCH FUNCTION
			break;
		case 3:
			deleteData();   //CALLING THE FUNCTION TO DELETE DATA 
			break;
		case 4:
			displayData();       //CALLING THE FUNCTION TO DISPLAY DATA
			break;

		case 5:
			receipt();       //CALLING THE FUNCTION TO PRINT RECEIPT
			break;
		case 6:
			cout << "program ended :)" << endl;       //DISPLAYING MESSAGE 
			break;
		default:
			cout << "invalid input";               //DISPLAYING MESSAGE 
		}
	} while (choice != 6);               //until the user does not enter number 6
	system("pause");
	return 0;

}