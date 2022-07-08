#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<stdlib.h>
#include<iomanip>
using namespace std;
void enter() {
	int i, records;              //declaring variables 
	string arr[10][4];               //declaring array 
	ofstream write("data_entry.txt", ios::app);       //creating ofstream object
	if (!write.is_open())            //if file is not open
	{
		cout << "Error! File not opened." << endl;     //display message 

	}
	else                                 //if file is opened 
	{
		cout << "Enter number of records you want to enter:" << endl;   //prompt the user for input 
		cin >> records;   //storing input in variable 
		system("cls");
		cout << "\t\t\t-----------------------NOBLE PHARMACY------------------------\n" << endl;
		//write << "ID\t\t\t Name\t\t Price\t\tStock"<< endl;

		for (i = 0; i < records; i++)                    //loop to enter data 
		{
			cout << "Enter Id:\t";
			do {
				//prompt the user for input                        
				cin >> arr[i][0];
				if (arr[i][0].size() != 5)
					cout << "error!input id again : ";
			} while (arr[i][0].size() != 5);
			//storing input in variable

			write << arr[i][0] << "\t\t\t";                //writing data to file 

			cout << "Enter Name:\t";                    //prompt the user for input 
			cin >> arr[i][1];                              //storing input in variable 
			write << arr[i][1] << "\t\t   ";                    //writing data to file
			cout << "Enter price:\t";                      //prompt the user for input 
			cin >> arr[i][2];                               //storing input in variable 
			write << arr[i][2] << "\t\t\t\t";                      //writing data to file
			cout << "Enter stock remaining:\t";              //prompt the user for input 
			cin >> arr[i][3];                                   //storing input in variable 
			write << arr[i][3] << "\t\t\t";                        //writing data to file

			cout << endl;                 //moving the control to new line on console 
			write << "\n";                 //moving the control to new line in the file 
			system("cls");
			cout << "\t\t\t-----------------------NOBLE PHARMACY----------------------\n" << endl;
			cout << " Enter your next product " << endl;
		}


		system("pause");
		system("cls");
		write.close();              //closing the file 
	}
}

void search()
{
	char choice;           //declaring variables 
	int j, k;                     //declaring variables 
	string  i;                        //declaring variables 
	string arr[10][4];                      //declaring array
	ifstream read("data_entry.txt");               //creating an object of ifstream

	if (read.is_open())             //if file is opened 
	{
		while (!read.eof())         //until the control reaches the end of file 
		{
			for (k = 0; k < 10; k++)            //loop to read from the file 
			{
				for (j = 0; j < 4; j++)
				{
					read >> arr[k][j];             //reading from a file 
				}
			}
		}
	}
	else                              //if file is not opened 
		cout << "File not opened" << endl;         //display message 
find:
	bool found = 0;
	cout << "Enter the ID number you want to search:  ";     //prompt the user for input 
	cin >> i;
	cout << endl;                          // storing the input in variable 
	for (k = 0; k < 10; k++)             // loop to search for the specific record 
	{
		for (j = 0; j < 4; j++)
		{
			if (arr[k][0] == i)
			{
				for (j = 0; j < 4; j++)
					cout << arr[k][j] << "\t";
				found = 1;
			}

		}
	}
	if (!found)
		cout << "\nid not found";

	cout << endl << endl;            //moving the control to new line 
	cout << "Do you want to search another record?(Y/N)" << endl;       //prompt the user for input 
	cin >> choice;                               //storing record from a file 
	char ch = toupper(choice);                     //if character is lowercase change to uppercase
	if (ch == 'Y')                       //if choice is Y
	{
		system("cls");
		cout << "\t\t\t\t------------------------MENU-------------------------" << endl;
		cout << "\t\t\t-----------------------WELCOME TO NOBLE PHARMACY----------------------\n" << endl;
		goto find;                         // go to find label 
	}
	else if (ch == 'N')                             //if choice is N
		cout << "Program ended" << endl;          //display message 
	else                                               //if choice is anything else 
		cout << "invalid input" << endl;           //display message 
	system("pause");
	system("cls");
	read.close();                  // close the file 
}

//delete function--------------------------

void deleteData()

{  
	string arr[10][4], id;                //declaring variables 
	ifstream read("data_entry.txt");             //declaring variable of ifstream 
	int r, c;                          //declaring variables 
	cout << "Enter id to delete:" << endl;   //prompt the user for input 
	cin >> id;                             //storing the input in variable 
	for (r = 0; r < 10; r++) {             //loop to read from file 
		arr[r][0] = " ";
	}
	for (r = 0; r < 10; r++)
	{
		for (c = 0; c < 4; c++)
		{
			read >> arr[r][c];
			cout << arr[r][c] << "\t";
		}
		cout << endl;                      //moving the control to next line 
	} 
	read.close();                         //closing the file 
	ofstream write("data_entry.txt");         //declaring variable of ofstream 
	bool found = 0;                             //declaring variable 

	for (r = 0; r < 10; r++)                  //loop to write data except the deleted one 
	{
		for (c = 0; c < 4; c++)
		{
			if (arr[r][0] != id && arr[r][0] != " ")
			{
				write << arr[r][c] << "\t\t";            //writing data to file 
				found = 1;
			}

		}
		if (arr[r][0] != id && arr[r][0] != " ")
			write << endl;                 //moving the control to next line 
	}
	if (!found)                        //if entered id is not found 
		cout << "record not found";               //display message 
	write.close();                          //closing the file 

}


//displaydata function begins here----------------------------------
void displayData()
{
	int r, c;               //declaring variables 
	ifstream display("data_entry.txt");       //Creating an object of ifstream 
	string arr[10][4];           //declaring array 

	if (display.is_open())         //if file is opened
	{
		while (!(display.eof()))        // until the control reaches the end of file 
		{
			for (r = 0; r < 10; r++)          // loop to read from file and displaying 
			{
				for (c = 0; c < 4; c++)
				{
					display >> arr[r][c];            //reading from file 
					cout << arr[r][c] << "\t   ";          //displaying on console 

				}
				cout << endl;                    //moving the control to newline 

			}
		}
	}

	else
		cout << "File not opened!" << endl;        //display message 
	display.close();                              //close the file 
	system("pause");
}
//------------------- starting reciept function//--------
void receipt()
{
	int quantity, bill, price;
	int r, c, stock;


	string mobile;
	string i, id;
	string arr[10][4];                      //declaring array
	ifstream read("data_entry.txt");               //creating an object of ifstream
	for (r = 0; r < 10; r++) {
		arr[r][0] = " ";
	}
	if (read.is_open())             //if file is opened 
	{
		while (!read.eof())         //until the control reaches the end of file 
		{
			for (r = 0; r< 10; r++)            //loop to read from the file 
			{
				for (c = 0; c < 4; c++)
				{
					read >> arr[r][c];    //reading from a file


				}
			}
		}
	}
	else                              //if file is not opened 
		cout << "File not opened" << endl; //display message


	string name;
	cout << "Enter your name : ";
	cin >> name;
	cout << "Enter your mobile number : ";
	cin >> mobile;
	cout << "Enter the id you want to order:";
	cin >> id;
	cout << "Enter quantity :";
	cin >> quantity;

	ofstream write("data_entry.txt");

	//checking the specific record and decrementing  the stock
	for (r = 0; r < 10; r++)
	{
		for (c = 0; c < 4; c++)
		{
			if (arr[r][0] != " ") {
				if (arr[r][0] == id)             //id exists at first column
				{
					if (c == 3)               //if id matches then checks the stock in 4th col
					{
						
						stock = stoi(arr[r][3]);          //changing string to integer 
						if (quantity < stock)
						{
							stock = stock - quantity;
							write << stock;
						}
						else
							cout << "you are low in stock!";
					}
					else
						write << arr[r][c] << "\t";
				}
				else
					write << arr[r][c] << "\t";

			}
		}
		if (arr[r][0] != " ")
			write << endl;            //moving the control to nextline 
	}
	write.close();               //closing the file 




	for (r = 0; r < 10; r++)           //loop to calculate bill 
	{
		for (c = 0; c < 4; c++)
		{
			if (arr[r][0] == id)
			{
				if (c == 2)
				{
					price = stoi(arr[r][2]);             //changing string into integer 
					bill = quantity * price;             //calculating bill 
				}


			}

		}
	}
	
	system("pause");
	system("cls");
	cout << " \t\t---------NOBLE PHARMACY----------" << endl;
	cout << setw(35) << "Reciept\n";
	cout << setw(45) << "_____" << setw(14) << "\n";
	cout << "\t\t\tName: " << name;
	cout << "\n\n\t\tMobile number...........+92";
		
	cout << mobile << setw(9) << "\n";
	cout << endl;


	for (r = 0; r < 10; r++)             // loop to search for the specific record and print in reciept 
	{
		for (c = 0; c < 4; c++)
		{
			if (arr[r][0] == id)
			{
				for (c = 1; c <= 2; c++)
				{
					if (c == 1)
						cout << "\t\tName of medicine : " << arr[r][c] << endl;
					if (c == 2)
						cout << "\t\tPrice per medicine : " << arr[r][c] << endl;
				}

			}

		}
	}
	cout << "\n\t\tQuantity :\t" << quantity << endl;
	cout << "\t\tTotal Bill : \t" << bill << endl;
	cout << "\n\n\t\t >>Thank You For Visiting<<";

	cout << setw(13) << "\n";
	cout << setw(49) << "\n\n";

	cout << setw(30) << "* * *" << setw(24) << "\n";
	cout << setw(48);
	cout << "\n\t";

	for (int j = 0; j < 48; j++)
		cout << "_";
	cout << endl;
	system("pause");
	
}

