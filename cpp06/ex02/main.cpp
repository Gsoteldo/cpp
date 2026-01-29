#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdexcept>



int getRandomType() {
	srand(time(NULL));
	return (rand() % 3);
}


void identify(Base *base) {
	if (dynamic_cast<A*>(base))
		std::cout << "It's A" << std::endl;
	if (dynamic_cast<B*>(base))
		std::cout << "It's B" << std::endl;
	if (dynamic_cast<C*>(base))
		std::cout << "It's C" << std::endl;
}

void identify (Base &base) {
	
	try {
		A &a = dynamic_cast<A&>(base);
		(void)a;
		std::cout << "It's A" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what()<< " it's not A" << std::endl;
	}

	try {
		B &b = dynamic_cast<B&>(base);
		(void)b;
		std::cout << "It's B" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what()<< " it's not B" << std::endl;
	}

	try {
		C &c = dynamic_cast<C&>(base);
		(void)c;
		std::cout << "It's C" << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << " it's not C" << std::endl;
	}
	

	
}


Base *generate() {
	int type = getRandomType();
	switch (type)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

int main() {
	Base *base = generate();

	std::cout << "---Identify by pointer:" << std::endl;
	identify(base);
	std::cout << "---Identify by reference:" << std::endl;
	identify(*base);


	delete base;
	return (0);
}