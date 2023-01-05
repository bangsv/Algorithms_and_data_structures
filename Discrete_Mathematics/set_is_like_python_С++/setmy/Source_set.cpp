#include "Header_set.h"

Set::Set() {
	element.resize(0);
	universem.resize(0);
}

Set::Set(int size) {
	element.resize(size);
}

Set::Set(std::initializer_list<int> list) {
	for (auto x : list)
		element.push_back(x);

	unical_valua(element);
}

void Set::setUnivers(std::initializer_list<int> list) {
	for (auto x : list)
		universem.push_back(x);
}

void Set::setUnivers(int n) {
	for (int i = 1; i <= n; i++)
		universem.push_back(i);
}

size_t Set::size() {
	return element.size();
}

//Removing duplicate values from a vector
void Set::unical_valua(data& number) {
	sort(number.begin(), number.end());
	number.erase(unique(number.begin(), number.end()), number.end());
}

//The operation of union of two sets
Set Set::Union(Set one) {
	Set ret(one);

	ret.element.insert(ret.element.begin(),
		element.begin(), element.end());

	unical_valua(ret.element);
	ret.universem = universem;
	return ret;
}


Set Set::Intersection(Set one) {
	Set ret;
	int i = 0, j = 0;
	while (i < one.element.size() && j < element.size()) {
		if (one.element.at(i) == element.at(j)) {
			ret.element.push_back(one.element.at(i));
			j++;
		}
		else if (one.element.at(i) > element.at(j))
			j++;
		else
			i++;
	}
	ret.universem = universem;
	return ret;
}

bool Set::search(int n, data info) {
	for (int i = 0; i < info.size(); ++i)
		if (info.at(i) == n)
			return true;

	return false;
}


Set Set::Difference(Set one) {
	Set ret;
	int i = 0;
	for (int i = 0; i < element.size(); i++)
		if (!search(element.at(i), one.element))
			ret.element.push_back(element.at(i));
	ret.universem = universem;
	return ret;
}

// Symmetric difference
Set Set::Xor(Set one) {
	int i = 0, j = 0;
	Set ret;
	while (i < element.size() && j < one.element.size()) {
		if (element.at(i) == one.element.at(j)) {
			i++;
			j++;
		}
		else if (element.at(i) > one.element.at(j))
			ret.element.push_back(one.element.at(j++));
		else
			ret.element.push_back(element.at(i++));
	}
	while (i < element.size())
		ret.element.push_back(element.at(i++));

	while (j < one.element.size())
		ret.element.push_back(one.element.at(j++));

	ret.universem = universem;
	return ret;

}

bool Set::Strict_inclusion(Set one) {
	bool flag = element.size() < one.element.size();
	int i = 0;
	while (i < element.size() && flag)
		flag = search(element.at(i++), one.element);

	return flag;

}

Set Set::Denial() {
	Set ret;
	ret.universem = universem;
	for (int i = 1; i <= universem.size(); i++)
		if (!search(i, element))
			ret.element.push_back(i);
	return ret;
}

std::ostream& operator<< (std::ostream& os, Set mydata) {
	std::cout << "{ ";
	for (int i = 0; i < mydata.size(); i++) {
		if (i == mydata.size() - 1) {
			os << mydata.element.at(i) << " }";
			return os;
		}
		os << mydata.element.at(i) << ", ";
	}
	return os;
}

bool Enabling(Set one, Set two) {
	return one.element == two.element ? 1 : 0;
}

Set operator ! (Set one) {
	return one.Denial();
}

Set operator ^ (Set one, Set two) {
	return one.Xor(two);
}

bool operator >= (Set one, Set two) {
	return one.Strict_inclusion(two);
}

Set operator & (Set one, Set two) {
	return one.Intersection(two);
}

Set operator | (Set one, Set two) {
	return one.Union(two);
}

Set operator - (Set one, Set two) {
	return one.Difference(two);
}

bool operator == (Set one, Set two) {
	return Enabling(one, two);
}