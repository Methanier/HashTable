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

	const bool operator==(const PhoneListing & inListing)
	{
		return (name == inListing.GetName()) ? true : false;
	}

	const bool operator!=(const PhoneListing & inListing)
	{
		return !(name == inListing.GetName()) ? true : false;
	}

private:
	string name;
	string phoneNumber;
};


template<>
class hash<PhoneListing>
{
public:
	size_t operator()(const PhoneListing & pl) const
	{
		static hash<string> h;
		unsigned int result = h(pl.GetName());
		return result;
	}
};

