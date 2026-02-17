# include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &obj): std::stack<T, Container>(obj) {

}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &obj) {
	if (this != &obj) {
		std::stack<T, Container>::operator=(obj);
	}
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const {
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return (this->c.end());
}

		template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const {
	return (this->c.end());
}

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& out, const MutantStack<T, Container> &obj) {
	out << "MutantStack contents: ";
	for (typename MutantStack<T, Container>::const_iterator it = obj.begin(); it != obj.end(); ++it) {
		out << *it << " ";
	}
	return out;
}