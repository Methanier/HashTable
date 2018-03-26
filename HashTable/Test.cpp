/*
	Charles Cozart
	CSC382
	Hash Table Testing
*/
#include<stdlib.h>
#include<iostream>
#include"HashTable.h"
#include "PhoneListing.h"

using namespace std;

//Function ProtoTypes
void AutoTestConstructor(); 
void AutoTestInsert();
void AutoTestContains();
void AutoTestRetrieve();
void AutoTestGetListSize();
void AutoTestToString();
void AutoTestReHash();
void AutoTestRemove();
void AutoTestMakeEmpty();
void RunAutoTests();

bool ManualTestConstructor();
void ManualTestInsert();
void ManualTestContains();
void ManualTestRetrieve();
void ManualTestToString();
void ManualTestRemove();
void ManualTestReHash();
PhoneListing * CreatePhoneListing();
void RunManualTests();

void UserOptions();

//HashTables for testing
HashTable<PhoneListing> *autoTestTable;
HashTable<PhoneListing> *manualTestTable;

//Program starts here
int main()
{
	UserOptions();
}

void AutoTestConstructor()
{
	autoTestTable = new HashTable<PhoneListing>(); //initialize hash table

	//Prints result
	(autoTestTable != nullptr) ? cout << "Constructor Works." << endl : cout << "Fail on Auto Constructor." << endl;

}

void AutoTestInsert()
{
	PhoneListing *temp = new PhoneListing("Charles", "480-787-1815"); //Create temp PhoneListing
	autoTestTable->Insert(*temp); //Calls insert function on autoTestTable

	//Calls Contains function on autoTestTable prints based on return value
	(autoTestTable->Contains(*temp)) ? cout << "Insert Works." << endl : cout << "Fail on Insert." << endl;
}

void AutoTestContains()
{
	PhoneListing *temp = new PhoneListing("Holly", "111-111-1111"); //Create temp PhoneListing
	autoTestTable->Insert(*temp); //Calls insert function on AutoTestTable

	//Calls Contains function on autoTestTable prints based on return value
	(autoTestTable->Contains(*temp)) ? cout << "Contains Works." << endl : cout << "Fail on Contains." << endl;
}

void AutoTestRetrieve()
{
	PhoneListing *temp = new PhoneListing("Dave", "222-222-2222"); //Create temp PhoneListing
	autoTestTable->Insert(*temp); //Calls Insert function on autoTestTable
	
	string value = autoTestTable->Retrieve("Dave"); //Sets string to result returned from call to Retrieve on autoTestTable

	//Prints based on if value is the same as temp listings phone number
	(value == "222-222-2222") ? cout << "Retrieve Works." << endl : cout << "Fail on Retrieve." << endl;
}

void AutoTestGetListSize()
{
	int size = autoTestTable->Size(); //Sets size to return value of autoTestTable's Size function

	//Prints based on if size has been intialized with a value
	(size != NULL) ? cout << "GetListSize Works." << endl : cout << "Fail on GetListSize" << endl;
}

void AutoTestToString()
{
	string test = ""; //Initialize variable
	test = autoTestTable->ToString(); //set test to value return from autoTestTable's ToString function
	 
	//Prints based on if test is "empty"
	(test != "") ? cout << "ToString Works." << endl : cout << "Fail on ToString." << endl;
}

void AutoTestReHash()
{
	int previousSize = autoTestTable->Size(); //Variable to hold the previous size of the hash table

	autoTestTable->ReHash(); //Calls Rehash Function

	 //Prints based on if rehash worked
	(autoTestTable->Size() > previousSize) ? cout << "ReHash Works." << endl : cout << "Fail on ReHash." << endl;
}

void AutoTestRemove()
{
	PhoneListing *temp = new PhoneListing("Charles", "480-787-1815"); //Creates phone listing

	autoTestTable->Remove(*temp); //Calls remove on autoTestTable

	//Prints on if autoTestTable still contains temp Phone listing
	(!autoTestTable->Contains(*temp)) ? cout << "Remove Works." << endl : cout << "Fail on Remove" << endl;
}

void AutoTestMakeEmpty()
{
	PhoneListing *tempOne = new PhoneListing("Holly", "111-111-1111"); //Create temp PhoneListing
	PhoneListing *tempTwo = new PhoneListing("Dave", "222-222-2222"); //Create temp PhoneListing

	autoTestTable->MakeEmpty(); //Calls MakeEmpty function on autoTestTable

	//Prints based on if autoTestTable still contains either of the temp variables or not
	(!autoTestTable->Contains(*tempOne) || !autoTestTable->Contains(*tempTwo) || (!autoTestTable->Contains(*tempOne) && !autoTestTable->Contains(*tempTwo))) 
		? cout << "MakeEmpty Works." << endl : cout << "Fail on MakeEmpty" << endl;
}

//Runs all autoTest functions
void RunAutoTests()
{
	AutoTestConstructor();
	AutoTestInsert();
	AutoTestContains();
	AutoTestRetrieve();
	AutoTestGetListSize();
	AutoTestToString();
	AutoTestReHash();
	AutoTestRemove();
	AutoTestMakeEmpty();
}

bool ManualTestConstructor()
{
	manualTestTable = new HashTable<PhoneListing>(); //initialize manualTestTable

	return (manualTestTable != nullptr) ? true : false; //returns based on if manualTestTable is a nullptr
}

void ManualTestInsert()
{
	string inputString;
	//If manutalTestTable hasn't been created print warning
	if (manualTestTable == nullptr)
	{
		cout << "Please initialize the hashTable before adding listings." << endl;
		return;
	}
	//While user hasn't entered n or N
	while (inputString != "n" && inputString != "N")
	{
		//prints menu
		cout << endl;
		cout << "Whould you like to create a phone listing to add to the hash table? Y/N" << endl;
		getline(cin, inputString);
		//If user input y or Y
		if (inputString == "y" || inputString == "Y")
		{
			PhoneListing *temp = CreatePhoneListing(); //Create temp PhoneListing calling CreatePhoneListing function
			manualTestTable->Insert(*temp); //Call insert on manualTestTable
			cout << temp->ToString() << " was added to the table." << endl; //Print completion
		}
		//If user did NOT input n or N prints warning
		else if (inputString == "n" || inputString == "N")
		{
			return;
		}
		else
		{
			cout << "Invalid input, please select an option" << endl;
		}
	}
}

void ManualTestContains()
{
	//If manualTestTable has been initalized
	if (manualTestTable != nullptr)
	{
		string userInput;
		
		//While user has not input n or N
		while (userInput != "n" || userInput != "N")
		{
			//Print options
			cout << endl;
			cout << "Would you like to search for a phone listing? Y/N" << endl;
			getline(cin, userInput);

			//If user input y or Y
			if (userInput == "y" || userInput == "Y")
			{
				PhoneListing *temp = CreatePhoneListing(); //Create temp PhoneListing calling CreatePhoneListing function
				//Calls Contains on manutalTestTable prints result on if temp was found
				(manualTestTable->Contains(*temp)) ? cout << temp->ToString() << " was found in the table" << endl : cout << temp->ToString() << " was not found in the table" << endl;
			}
			//If user did NOT input n or N prints warning
			else if (userInput != "n" || userInput != "N")
			{
				return;
			}
			else
			{
				cout << "Invalid input, please select an option" << endl;
			}
		}
	}
	//Prints warning if manualTestTable is not initalized
	else
	{
		cout << "Please initialize the Hash Table before searching." << endl;
	}
}

void ManualTestRetrieve()
{
	//If manualTestTabl is not initalized prints warning
	if (manualTestTable == nullptr)
	{
		cout << "Please initialize the Hash Table before attempting to retrieve." << endl;
		return;
	}

	string userInput;

	//While user has not input n or N
	while (userInput != "n" || userInput != "N")
	{
		//Prints options
		cout << endl;
		cout << "Would you like to retrieve a phone number? Y/N" << endl;
		getline(cin, userInput);

		//If user input y or Y
		if (userInput == "y" || userInput == "Y")
		{
			string name;
			cout << "Enter the name of the person who's number you want to retrieve." << endl;
			getline(cin, name);
			string number = "";
			number = manualTestTable->Retrieve(name); //Calls Retrieve function on manualTestTable using user input for name/key

			(number != "") ? cout << "The phone number for " << name << " is " << number << endl : cout << "There is no listing for " << name << " in the table." << endl;
		}
		//If user did NOT input n or N prints warning
		else if (userInput == "n" || userInput == "N")
		{
			return;
		}
		else
		{
			cout << "Invlaid input, please select an option" << endl;
		}
	}
}

void ManualTestToString()
{
	//If manualTestTable has not been initialized prints warning
	if (manualTestTable == nullptr)
	{
		cout << "Please initialize the Hash Table before printing listings." << endl;
		return;
	}

	cout << "Hash Table" << endl << endl; //Header

	cout << manualTestTable->ToString() << endl; //Calls ToString on manualTestTable and prints to console
}

void ManualTestRemove()
{
	//If manualTestTable has not been initalized prints warning
	if (manualTestTable == nullptr)
	{
		cout << "Please initialize the Hash Table before attempting to remove." << endl;
		return;
	}

	string userInput;
	
	//While user has not input n or N
	while (userInput != "n" || userInput != "N")
	{
		//Prints options
		cout << endl;
		cout << "Would you like to remove a listing from the table? Y/N" << endl;
		getline(cin, userInput);

		//If user input y or Y
		if (userInput == "y" || userInput == "Y")
		{
			PhoneListing *temp = CreatePhoneListing(); //Creates temp PhoneListing

			//If the PhoneListing was not found prints that it wasn't
			if (!manualTestTable->Contains(*temp))
			{
				cout << temp->ToString() << " was not found in the table." << endl;
			}
			//If phone listing is found, removes from table, prints that it was removed
			else
			{
				manualTestTable->Remove(*temp);
				cout << temp->ToString() << " was removed from the table." << endl;
			}
		} 
		//If user did NOT input n or N prints warning
		else if (userInput == "n" || userInput == "N")
		{
			return;
		}
		else
		{
			cout << "Invalid input, please select an option." << endl;
		}
	}
}

void ManualTestReHash()
{
	//If manualTestTable has not been initalized prints warning
	if (manualTestTable == nullptr)
	{
		cout << "Please initialize the Hash Table before attempting to remove." << endl;
		return;
	}

	string userInput;
	int previousSize = manualTestTable->Size();

	//While user has not input n or N
	while (userInput != "n" || userInput != "N")
	{
		//Prints options
		cout << endl;
		cout << "Would you like to ReHash the table? Y/N" << endl;
		getline(cin, userInput);

		//If user input y or Y
		if (userInput == "y" || userInput == "Y")
		{
			manualTestTable->ReHash();

			cout << "The previous size of the table was " << previousSize << " elements." << endl;
			cout << "The curent size of the table is " << manualTestTable->Size() << " elements." << endl;
		}
		//If user did NOT input n or N prints warning
		else if (userInput == "n" || userInput == "N")
		{
			return;
		}
		else
		{
			cout << "Invalid input, please select an option." << endl;
		}
	}
}

PhoneListing * CreatePhoneListing()
{
	//Variables for employee object
	string listingName;
	string listingPhoneNumber;

	bool validInput = false;

	//variable for user input
	string inputString;

	//Loop continues while user input remains invalid
	while (!validInput)
	{
		//try block for invalid argument exceptions
		try
		{
			//Prints option
			cout << endl;
			cout << "Enter the Listing Name" << endl;
			getline(cin, inputString); //Gets user input
			listingName = inputString; //Sets listing name to user input

			//Prints option
			cout << endl << "Enter Listing Phone Number" << endl;
			getline(cin, inputString); //gets user input
			listingPhoneNumber = inputString; //Sets listing phone number to user input
			validInput = true;
		}
		//Catches exceptions thrown for invalid input
		catch (invalid_argument e1)
		{
			cout << e1.what() << endl << endl;
			validInput = false;
		}
	}

	PhoneListing *temp = new PhoneListing(listingName, listingPhoneNumber);

	return temp; //returns created PhoneListing
}

void RunManualTests()
{
	int userInput = -1; //Sets userInput

	//Loop to run while userInput does not equal 9
	while (userInput != 9)
	{
		//Manual test options
		cout << endl;
		cout << "Manual Testing Choose an option" << endl;
		cout << "1. Create HashTable of PhoneListing" << endl;
		cout << "2. Add to Table" << endl;
		cout << "3. Print Table" << endl;
		cout << "4. Search Table" << endl;
		cout << "5. Retrieve From Table" << endl;
		cout << "6. ReHash Table" << endl;
		cout << "7. Delete from Table" << endl;
		cout << "8.  Previous Menu" << endl;

		string inputString; //String to hold userInput from command line

		//Try block to catch exceptions from user input
		try {
			getline(cin, inputString); //Get user input from command line, set inputString to the value entered by the user

			userInput = stoi(inputString); //Convert user input to integer, set userInput variable to the integer

			//Switch based on userInput
			switch (userInput)
			{
			case 1:
				//Calls ManualTestContructor if result is true prints to console
				if (ManualTestConstructor())
					cout << "Succesfully created HashTable of type PhoneListing." << endl;
				break;
			case 2:
				ManualTestInsert();
				break;
			case 3:
				ManualTestToString();
				break;
			case 4:
				ManualTestContains();
				break;
			case 5:
				ManualTestRetrieve();
				break;
			case 6:
				ManualTestReHash();
				break;
			case 7:
				ManualTestRemove();
				break;
			case 8:
				UserOptions();
				break;
			default:
				//If userInput didn't throw an exception, but didn't fit this case calls RunManualTests funtion again
				cout << "Invalid Input. Please select an option" << endl;
				RunManualTests();
				break;
			}
		}
		//Catches invalid arugment exceptions for string to integer conversions, prints exception to console, then calls RunManualTests funtion
		catch (invalid_argument e1)
		{
			cout << e1.what() << endl << endl;
			RunManualTests();
		}
	}
}

//Function for User Options Menu
void UserOptions()
{
	int input = -1; //Variable for user input

					//Loop continues as long as input does not equal 3
	while (input != 3)
	{
		//Prints menu
		cout << endl << "Choose an Option Below!" << endl;
		cout << "1. Run Manual Testing of HashTable Class" << endl;
		cout << "2. Run Automatic Testing of HashTable Class" << endl;
		cout << "3. Exit Application" << endl;

		string inputString; //Variable for user input

		//Try block for invalid user input
		try
		{
			getline(cin, inputString); //gets user input

			input = stoi(inputString); //converts user input to int, sets input variable to that value


			//If user input was 1, calls RunManualTests
			if (input == 1)
			{
				RunManualTests();
			}
			//If user input was 2, calls RunAutoTests
			else if (input == 2)
			{
				RunAutoTests();
			}
			//If user input is anything but 1, 2 or 3, prints error, calls UserOptions again
			else if (input != 3)
			{
				cout << "Invalid Input please select an option" << endl << endl;
				UserOptions();
			}
		}
		//Catches exception from user input, prints exception, calls this function again
		catch (invalid_argument e1)
		{
			cout << e1.what() << endl << endl;
			UserOptions();
		}
	}
	exit(0); //exits application
}
