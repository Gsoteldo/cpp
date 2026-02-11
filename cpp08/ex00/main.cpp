#include "easyfind.hpp"


void EmptyContainerTest() {
	std::cout << "Test 1: Empty Container" << std::endl;
	std::vector<int> emptyV;

	try
	{
		easyfind(emptyV, 3);
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

void FoundNumberTest () {
	std::cout << "Test 2: Found Number" << std::endl;
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	try
	{
		easyfind(v, 30);
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

void NotFoundNumberTest() {
	std::cout << "Test 3: Not Found Number" << std::endl;
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	try
	{
		easyfind(v, 3);
	} catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

void NegativeNumbersTest() {
	std::cout << "Test 4: Negative Numbers" << std::endl;
    std::vector<int> v;
    v.push_back(-10);
    v.push_back(-20);
    v.push_back(0);
    v.push_back(10);
    try {
        easyfind(v, -20);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl;
}


void DuplicatesTest() {
	std::cout << "Test 5: Duplicates" << std::endl;
    std::vector<int> v;
    v.push_back(5);
    v.push_back(5);
    v.push_back(10);
    v.push_back(5);
    try {
        easyfind(v, 5); // Debe encontrar el primer 5 (índice 0)
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl;
}

void LargeVectorTest() {
	std::cout << "Test 6: Large Vector" << std::endl;
    std::vector<int> v;
    for (int i = 0; i < 1000; ++i)
        v.push_back(i);
    try {
        easyfind(v, 999); // Último elemento
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl;
}

void ListTest() {
	std::cout << "Test 7: List Container" << std::endl;
	std::list<int> myList;
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_back(40);
	myList.push_back(50);

	try {
		easyfind(myList, 30);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}

void DequeTest() {
	std::cout << "Test 8: Deque Container" << std::endl;
	std::deque<int> myDeque;
	myDeque.push_back(10);
	myDeque.push_back(20);
	myDeque.push_back(30);
	myDeque.push_back(40);
	myDeque.push_back(50);

	try {
		easyfind(myDeque, 30);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}


int main() {
	EmptyContainerTest();
	FoundNumberTest();
	NotFoundNumberTest();
	NegativeNumbersTest();
	DuplicatesTest();
	LargeVectorTest();

	ListTest();
	DequeTest();

	return (0);
}