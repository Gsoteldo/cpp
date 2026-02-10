#include "iter.hpp"

void increment(int &x) {
	x++;
}

void increment (char &x) {
	x++;
}

void setZero (int &x) {
	x = 0;
}

void testPrint() {
	int array[4] = {1, 2, 3, 4};
	std::cout << "Print Array:" << std::endl;
	::iter(array, 4, printArray<int>);
	std::cout << std::endl;
}


void testIncrementInt() {
	int array[4] = {1, 2, 3, 4};
	std::cout << "Increment Values" << std::endl;
	::iter(array, 4, increment);
	::iter(array, 4, printArray<int>);
	std::cout << std::endl;
}

void testSetZero() {
	int array[4] = {1, 2, 3, 4};
	std::cout << "Set Values to Zero" << std::endl;
	::iter(array, 4, setZero);
	::iter(array, 4, printArray<int>);

	std::cout << std::endl;
}

void testIncrementChar() {
	char array[5] = "Hola";
	std::cout << "Increment Values" << std::endl;
	::iter(array, 5, increment);
	::iter(array, 5, printArray<char>);
	std::cout << std::endl;
}

void testNullPointer() {
	int *array = NULL;
	std::cout << "Test: NULL pointer" << std::endl;
	::iter(array, 4, printArray<int>); // No debe hacer nada, no se llama a la función de impresión


	int array2[4] = {1, 2, 3, 4};
	std::cout << "Test: Length zero" << std::endl;
	::iter(array2, 0, printArray<int>); // No debe hacer nada, no se llama a la función de impresión

	std::cout << std::endl;
}

int main() {
	int array[4] = {1 ,2, 3, 4 };

	::iter(array, 4 , ::printArray<int>);

	//Test incrementing values
	testIncrementInt();
	testIncrementChar();

	//Test print
	testPrint();

	//Test set to zero
	testSetZero();

	//Test null pointer
	testNullPointer();

	return (0);
}