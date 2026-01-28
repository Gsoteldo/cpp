#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdexcept>



int getRandomType() {
	srand(time(NULL));
	return (rand() % 3);
}


Base * generate() {
	int type = getRandomType();
	switch (type)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
}

int main() {
	Base *base = generate();

	
	delete base;
	return (0);
}