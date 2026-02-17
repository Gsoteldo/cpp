
#include "MutantStack.hpp"
#include <list>


//Test de copia y asignación
void copyAssingTest() {
	MutantStack<int> m1;
    m1.push(1); m1.push(2); m1.push(3);
    MutantStack<int> m2(m1);
    MutantStack<int> m3;
    m3 = m1;

    m2.push(4);
    m3.push(5);

    std::cout << "Copia top: " << m2.top() << ", Original top: " << m1.top() << std::endl;
    std::cout << "Asignación top: " << m3.top() << std::endl;
}

//Test de vacío
void emptyTest() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.pop();
	mstack.pop();
	mstack.pop();
	mstack.pop();
	mstack.pop();
	mstack.pop();
	std::cout << "Stack empty: " << (mstack.empty() ? "Yes" : "No") << std::endl;
}

//Test de stack vacio
void emptyStackTest() {
	MutantStack<int> mstack;
	std::cout << "Stack empty: " << (mstack.empty() ? "Yes" : "No") << std::endl;
}

//Test de strings
void stringTest() {

	MutantStack<std::string> m;
    m.push("hola");
    m.push("mundo");
    while (m.size()) {
		std::cout << m.top() << std::endl;
    	m.pop();
    }
}

//Test de double
void doubleTest() {
	MutantStack<double> m;
	m.push(1.1);
	m.push(2.2);
	m.push(3.3);
	while (m.size()) {
		std::cout << m.top() << std::endl;
		m.pop();
	}
}

//Test de compatibilidad con std::stack
void stackCompatibilityTest() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::stack<int> s(mstack);

	std::cout << "Std::stack contents:" << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	
	
}

//Test de cambio a lista
void listTest() {
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
}


//Test dado por 42
void mainTest42() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

int main() {
	mainTest42();
	std::cout << "-----------------" << std::endl;
	std::cout << "Test de copia y asignación:" << std::endl;
	copyAssingTest();
	std::cout << "-----------------" << std::endl;
	std::cout << "Test de stack vacío:" << std::endl;
	emptyTest();
	std::cout << "-----------------" << std::endl;
	std::cout << "Test de lista:" << std::endl;
	listTest();
	std::cout << "-----------------" << std::endl;
	std::cout << "Test de compatibilidad con std::stack:" << std::endl;
	stackCompatibilityTest();
	std::cout << "-----------------" << std::endl;
	std::cout << "Test de stack vacío:" << std::endl;
	emptyStackTest();
	std::cout << "-----------------" << std::endl;
	std::cout << "Test de strings:" << std::endl;
	stringTest();
	std::cout << "-----------------" << std::endl;
	std::cout << "Test de double:" << std::endl;
	doubleTest();

	return (0);
}