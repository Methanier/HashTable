/*
	Charles Cozart
	CSC382
	Hash Table
*/

#pragma once
#include<string>
#include"HashTable.h"

using namespace std;

class PhoneListing
{
public:
	//Constructors
	PhoneListing()
	{
		name = "";
		phoneNumber = "";
	}
	PhoneListing(string n) : name{ n } {}
	PhoneListing(string n, string p) : name{ n }, phoneNumber{ p } {}

	
	const string & GetName() const
	{
		return name;
	}

	const string & GetPhoneNumber() const
	{
		return phoneNumber;
	}

	//Operator Overloads
	const bool operator==(const PhoneListing & inListing) const
	{
		return (name == inListing.GetName()) ? true : false;
	}

	const bool operator!=(const PhoneListing & inListing) const
	{
		return !(name == inListing.GetName()) ? true : false;
	}

	string ToString()
	{
		return "Name: " + name + " Phone Number: " + phoneNumber;
	}

private:
	string name;
	string phoneNumber;
};

//Overloads hash class with PhoneListing for size_t operator () overload
template<>
class hash<PhoneListing>
{
public:
	//Overloads size_t operator () for PhoneListing class on hash class
	size_t operator()(const PhoneListing & pl) const
	{
		static hash<string> h;
		unsigned int result = h(pl.GetName());
		return result;
	}
};

