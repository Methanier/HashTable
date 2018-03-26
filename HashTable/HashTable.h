/*
	Charles Cozart
	CSC382
	Hash Table
*/

#pragma once
#include<vector>
#include<algorithm>
#include<math.h>
#include<list>

using namespace std;

template<typename T>
class HashTable
{
public:
	//Constructor, sets initial size to 17 (prime number)
	explicit HashTable(int size = 17)
	{
		hashLists.resize(size);
	}

	//Returns if the value passed is in the hash table
	bool Contains(const T & item)
	{
		auto & whichList = hashLists[thisHash(item)]; //Sets the variable whichList to the list within the vector that has the same index as the hash value of item
		return find(begin(whichList), end(whichList), item) != end(whichList); //returns true if item is found in whichList, false if not using the find function from algorithm
	}

	//Returns a string corresponding to the value associated with the passed in key of the hash table
	string & Retrieve(const string & key)
	{
		auto & listToRetrieve = hashLists[thisHash(key)]; //sets the list to retrieve from to the list within the vector with the same index as the hash value of the key
		string *value = nullptr; //initialize string pointer

		//Foreach loop iterating through listToRetrieve
		for each (T item in listToRetrieve)
		{
			if (item.GetName() == key) //if the current object .GetName() returns same value as the key
			{
				value = new string(item.GetPhoneNumber()); //Sets value to the Phone number (value) of the item
			}
		}

		if (value == nullptr)
			value = new string("");
		return *value;
	}
	
	//Insert object into hashTable
	void Insert(const T & item)
	{
		auto & whichList = hashLists[thisHash(item)]; //Returns the list at the index of the hash value of item

		if (find(begin(whichList), end(whichList), item) != end(whichList)) //If the item being passed in is already in the list return out of function, it's a duplicate
			return;
		whichList.push_back(item); //Adds item to list

		//Checks if currentSize of has table is greater than the hashLists size
		if (currentSize++ > hashLists.size())
			reHash();
	}

	//Insert object into hashTable
	void Insert(T && item)
	{
		auto & whichList = hashLists[thisHash(item)]; //Returns the list at the index of the hash value of item

		if (find(begin(whichList), end(whichList), item) != end(whichList)) //If the item being passed in is already in the list return out of function, it's a duplicate
			return;
		whichList.push_back(item); //Adds item to list

		//Checks if currentSize of has table is greater than the hashLists size
		if (currentSize++ > hashLists.size())
			reHash();
	}

	//Remove item from hash table
	void Remove(const T & item)
	{
		auto & listToRemoveFrom = hashLists[thisHash(item)]; //Returns the list at the index of the hash value of item

		auto iterator = find(begin(listToRemoveFrom), end(listToRemoveFrom), item); //Sets iterator variable to the returned value of the Find function if it exists in the list

		if (iterator == end(listToRemoveFrom)) //If the iterator is point to the "past the end" element of the list, return as it isn't referencing a valid item
			return;

		listToRemoveFrom.erase(iterator); //removes the item from the list
		--currentSize; //Decrements currentSize of HashTable
	}

	//Clears all the lists in the hash table
	void MakeEmpty()
	{
		//Variant of a foreach loop using auto keyword
		for (auto & thisList : hashLists)
		{
			thisList.clear(); //Calls the clear function on the current list in the hash table
		}
	}
	
	//Returns the size of the hash table
	int Size()
	{
		return hashLists.size();
	}

	//Returns a string of all the items in the hash table
	string ToString()
	{
		string result = ""; //Initialize variable
		//Variant of a foreach loop using auto keyword
		for (auto & listItr : hashLists)
		{
			list<T> tempList = listItr; //Creates a tempList set to the current list from the loop
			int listSize = tempList.size();

			//Runs while the temp list has items in it
			while (tempList.size() > 0)
			{
				T & item = tempList.front(); //sets a temporary variable to the first item in the temp list
				result += item.ToString() + " | "; // Calls item's tostring function and adds it to result
				tempList.pop_front(); //removes front item from the list
			}
			if (listSize > 0)
			{
				result += "\n"; //adds new line for the next list in the hash table
			}
		}
		return result;
	}
	
	//Public ReHash function used to test functionality of the private function
	void ReHash()
	{
		reHash();
	}

private:
	vector<list<T>> hashLists;
	int currentSize;

	//Resizes the hashTable
	void reHash()
	{
		vector<list<T>> oldLists = hashLists; //creates a temp vector of lists to hold the current hash table

		hashLists.resize(nextPrime(hashLists.size())); //Calls the resize function on the current vector using the nextPrime function passing in hashList.size()

		//Clears the current hash table
		for (auto & currentList : hashLists)
		{
			currentList.clear();
		}

		currentSize = 0;

		//Copies the items from the oldLists into the bigger hashLists
		for (auto & currentList : oldLists)
		{
			//Iterates through the currentList
			for (auto & item : currentList)
			{
				Insert(move(item)); //Calls the insert function on the item in the current list
			}
		}
	}

	//private function for creating hash values for the indexing of items
	size_t thisHash(const T & item)
	{
		static hash<T> hl; //creates a hash variable of type T (generic)
		unsigned int result = hl(item) % hashLists.size(); //Calls the hash operator () on the item passed in, sets result to remained returned from modulus division of the hashLists.size()
		return result;
	}

	//Doubles the number inserted then finds the next prime larger than that number
	int nextPrime(int prime)
	{
		int newPrime = prime * 2;

		//While the number is not prime
		while (!isPrime(newPrime))
		{
			newPrime++; //Increment the number
		}

		return newPrime;
	}

	//Checks if a given number is prime
	bool isPrime(int prime)
	{
		if (prime <= 1)
			return false;
		//If the number is 2 or 3 return true
		else if (prime <= 3)
			return true;
		//if the number is evenly divisable by 2 or 3 return false
		else if (prime % 2 == 0 || prime % 3 == 0) 
			return false;

		int i = 5;

		//While i squared is less than the number to check
		while (i * i <= prime)
		{
			//If the number is evenly divisible by i or i + 2 return false
			if (prime % i == 0 || prime % (i + 2) == 0)
				return false;
			i += 6; //all 6 to i based on the idea that all integers can be expressed as 6k + i where i = -1, 0, 1, 2, 3 or 4
		}
		return true;
	}
};
