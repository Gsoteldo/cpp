#include "Span.hpp"

int main() {

		Span prueba1 = Span(2);

		prueba1.addNumber(2);
		prueba1.addNumber(5);

		prueba1.longestSpan();

		// std::cout << 

		std::cout << "Longest Span: " << prueba1.getLongestSpan() << std::endl;

    return (0);
}