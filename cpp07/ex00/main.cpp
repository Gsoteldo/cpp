#include "whatever.hpp"

void testSwap() {
	// Test swap with integers
	{
		
		int a = 5;
    	int b = 3;

    	std::cout << "Before swap: a: " << a << ", b: " << b << std::endl;
    	::swap(a, b);
    	std::cout << "After swap: a: " << a << ", b: " << b << std::endl << std::endl;

	}
	// Test swap with floats
    {
        float c = 5.5f;
        float d = 3.3f;

    std::cout << "Before swap: c: " << c << ", d: " << d << std::endl;

    ::swap(c, d);

    std::cout << "After swap: c: " << c << ", d: " << d << std::endl;
	}
	// Test swap with characters
	{
		char e = 'A';
		char f = 'B';

		std::cout << "Before swap: e: " << e << ", f: " << f << std::endl;

		::swap(e, f);

		std::cout << "After swap: e: " << e << ", f: " << f << std::endl;
	}
	// Test swap with strings
	{
		std::string g = "Hello";
		std::string h = "World";

		std::cout << "Before swap: g: " << g << ", h: " << h << std::endl;

		::swap(g, h);

		std::cout << "After swap: g: " << g << ", h: " << h << std::endl;
	}
}

void testMin() {
	// Test min with integers
	{
		int a = 5;
		int b = 3;

		std::cout << "Min of a: " << a << ", b: " << b << " is " << ::min(a, b) << std::endl;
	}

	// Test min with floats
	{
		float c = 5.5f;
		float d = 3.3f;

		std::cout << "Min of c: " << c << ", d: " << d << " is " << ::min(c, d) << std::endl;
	}

	// Test min with characters
	{
		char e = 'A';
		char f = 'B';

		std::cout << "Min of e: " << e << ", f: " << f << " is " << ::min(e, f) << std::endl;
	}

	// Test min with strings
	{
		std::string g = "Hello";
		std::string h = "World";

		std::cout << "Min of g: " << g << ", h: " << h << " is " << ::min(g, h) << std::endl;
	}
}

void testMax() {
		// Test min with integers
	{
		int a = 5;
		int b = 3;

		std::cout << "Max of a: " << a << ", b: " << b << " is " << ::max(a, b) << std::endl;
	}

	// Test min with floats
	{
		float c = 5.5f;
		float d = 3.3f;

		std::cout << "Max of c: " << c << ", d: " << d << " is " << ::max(c, d) << std::endl;
	}

	// Test min with characters
	{
		char e = 'A';
		char f = 'B';

		std::cout << "Max of e: " << e << ", f: " << f << " is " << ::max(e, f) << std::endl;
	}

	// Test min with strings
	{
		std::string g = "Hello";
		std::string h = "World";

		std::cout << "Max of g: " << g << ", h: " << h << " is " << ::max(g, h) << std::endl;
	}
}

void personalTest() {
	// Test swap function
	testSwap();
	
	// Test min function
	testMin();
	
	//test max function
	testMax();
}

int main()
{
	//Personal Tests
	// personalTest();

	//42 Test
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		return 0;
	}

    return 0;
}