#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void ConstructorTest(Array<int> &test) {
	std::cout << "Test 1: Empty Constructor " << test << std::endl;

	//Test 2: Copy constructor
	Array<int> test2(test);
	std::cout << "Test 2: Copy Constructor " << test2 << std::endl;

	//Test 3: Assignment operator
	Array<int> test3;
	test3 = test;
	std::cout << "Test 3: Assignment Operator " << test3 << std::endl;

}

void BracketsTest(Array<int> &test) {
	std::cout << "Test 4: Operator [] " << test[2] << std::endl;

	//Test 5: Const Operator []
	const Array<int> constTest = test;
	std::cout << "Test 5: Const Operator [] " << constTest[2] << std::endl;
}

void DiferentsTypesTest() {
	Array<std::string> stringTest(3);
	for (unsigned int i = 0; i < stringTest.size(); i++) {
		stringTest[i] = "String " + std::to_string(i);
	}
	std::cout << "Test 7.1: Different Types " << stringTest << std::endl;

	Array<double> doubleTest(3);
	for (unsigned int i = 0; i < doubleTest.size(); i++) {
		doubleTest[i] = i * 0.5;
	}
	std::cout << "Test 7.2: Different Types " << doubleTest << std::endl;
}

void PersonalTest() {
	//Test 1: Constructor
	Array<int> test1(5);
	for (unsigned int i = 0; i < test1.size(); i++) {
		test1[i] = i;
	}
	ConstructorTest(test1);

	BracketsTest(test1);

	//Test 6: Size Function
	std::cout << "Test 6: Size Function " << test1.size() << std::endl;


	//Test 7: Diferents Types
	DiferentsTypesTest();

	//Test 8: Out of bounds
	try {
		std::cout << test1[10] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}


int main(int, char**)
{

	PersonalTest();

	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		
    	for (int i = 0; i < MAX_VAL; i++)
    	{
			if (mirror[i] not_eq numbers[i])
    	    {
				std::cerr << "didn't save the same value!!" << std::endl;
    	        return 1;
    	    }
    	}
    	try
    	{
			numbers[-2] = 0;
    	}
    	catch(const std::exception& e)
    	{
			std::cerr << e.what() << '\n';
    	}
    	try
    	{
			numbers[MAX_VAL] = 0;
    	}
    	catch(const std::exception& e)
    	{
			std::cerr << e.what() << '\n';
    	}

    	for (int i = 0; i < MAX_VAL; i++)
    	{
			numbers[i] = rand();
    	}
    	delete [] mirror;//
	}
    return 0;
}