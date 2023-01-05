#pragma once
#include <iostream>
#include <vector>
#include <initializer_list> 
#include <algorithm>
#include <set>

typedef std::vector<int> data;

class Set {
public:

	Set();

	Set(int size);

	Set(std::initializer_list<int> list);

	void setUnivers(std::initializer_list<int> list);

	void setUnivers(int n);

	size_t size();

private:
	data element;
	data universem;

	//Removing duplicate values from a vector
	void unical_valua(data& number);
	//The operation of union of two sets
	Set Union(Set one);
	Set Intersection(Set one);
	bool search(int n, data info);
	Set Difference(Set one);
	// Symmetric difference
	Set Xor(Set one);
	bool Strict_inclusion(Set one);
	Set Denial();
	friend bool Enabling(Set one, Set two);

	friend std::ostream& operator<<(std::ostream& os, Set mydata);
	friend Set operator | (Set one, Set two);
	friend Set operator & (Set one, Set two);
	friend Set operator - (Set one, Set two);
	friend Set operator ^ (Set one, Set two);
	friend Set operator ! (Set one);
	friend bool operator >= (Set one, Set two);

};


