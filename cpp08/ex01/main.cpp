#include "Span.hpp"

void test42() {

	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	} catch(const std::exception& e) {

		std::cerr << e.what() << '\n';
	}
}

void runExtraTests(int size) {

	//Test 0: Funcional
	try
	{
		Span prueba1 = Span(3);
		prueba1.addNumber(2);
		prueba1.addNumber(5);
		prueba1.addNumber(-8);
		
		std::cout << "Functional Test: " << prueba1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "You should not see this exception: " << e.what() << '\n';
	}

	//Test 1: Span Vacio
	try {
		Span prueba2 = Span();
		prueba2.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Expected exception (empty span): " << e.what() << '\n';
	}

    // Test 2: Excepción al añadir más de N elementos
    try {
        Span prueba4(2);
        prueba4.addNumber(1);
        prueba4.addNumber(2);
        prueba4.addNumber(3); // Debe lanzar excepción
    } catch(const std::exception& e) {
        std::cerr << "Expected exception (overflow): " << e.what() << std::endl;
    }

    // Test 3: Números repetidos
    try {
        Span prueba5(3);
        prueba5.addNumber(10);
        prueba5.addNumber(10);
        prueba5.addNumber(20);
        std::cout << "Shortest span (must be 0): " << prueba5.shortestSpan() << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 4: Solo un elemento
    try {
        Span prueba6(1);
        prueba6.addNumber(42);
        std::cout << prueba6.shortestSpan() << std::endl; // Excepción esperada
    } catch(const std::exception& e) {
        std::cerr << "Expected exception (only one element): " << e.what() << std::endl;
    }

    // Test 5: Números negativos y positivos
    try {
        Span prueba7(4);
        prueba7.addNumber(-50);
        prueba7.addNumber(0);
        prueba7.addNumber(50);
        prueba7.addNumber(100);
        std::cout << "Longest span (must be 150): " << prueba7.longestSpan() << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 6: Gran cantidad de números
    try {
        int sizeSpan = 10000;
        Span bigSpan(sizeSpan);
        bigSpan.randomAddNumber(sizeSpan);
        std::cout << "Big span test: " << bigSpan.longestSpan() << ", " << bigSpan.shortestSpan() << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	//Test 7: Cantidad de números especifico
	try
	{
		Span prueba3 = Span(size);

		prueba3.randomAddNumber(size);

		for (int i = 0; i < prueba3.getSize(); i++) {
			std::cout << prueba3.getVect()[i] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Specific numbers Test: " << prueba3 << std::endl;

	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}


int main() {

	
	test42();
	
	int size = 10;
	// runExtraTests(size);

	

	return (0);
}