/*
	Charles Cozart
	CSC382
	Hash Table
*/

#pragma once
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

template<typename T>
class HashTable
{
public:
	explicit HashTable(int size = 17)
	{
		hashLists.resize(size);
	}

	bool Contains(const T & item)
	{
		auto & whichList = hashLists[thisHash(item)];
		return (find(begin(whichList), end(whichList), item) != end(whichList);
	}
	T & Retrieve(int index); //TODO
	
	void Insert(const T & item)
	{
		auto & whichList = hashLists[thisHash(item)];

		if (find(begin(whichList), end(whichList), item) != end(whichList))
			return;
		whichList.push_back(item);

		//if (currentSize++ > hashLists.size())
			//reHash();
	}
	
	void Insert(T && item)
	{
		auto & whichList = hashLists[thisHash(item)];

		if (find(begin(whichList), end(whichList), item) != end(whichList))
			return;
		whichList.push_back(item);

		//if (currentSize++ > hashLists.size())
			//reHash();
	}
	void Remove(const T & item); //TODO
	void MakeEmpty(); //TODO
	
	int GetListSize()
	{
		return hashLists.size();
	}

private:
	vector<list<T>> hashLists;
	int currentSize;

	//void reHash(); //TODO

	size_t thisHash(const T & item)
	{
		static hash<T> hl;
		unsigned int result = hl(item) % hashLists.size();
		return result;
	}
};
