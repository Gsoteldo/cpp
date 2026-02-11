#include "Span.hpp"


const char* Span::OutOfRangeException::what() const throw() {
	return ("Out of Range");
}

Span::Span(): _vect(0), _maxSize(0) {}

Span::Span(unsigned int n): _vect(0), _maxSize(n) {}

Span::Span(const Span &obj): _vect(obj._vect), _maxSize(obj._maxSize) {}

Span &Span::operator=(const Span &obj) {
	if (this != &obj) {
		_vect = obj._vect;
		_maxSize = obj._maxSize;
	}

	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_vect.size() == _maxSize)
		throw OutOfRangeException();
	else {
		_vect.push_back(n);
	}
}

int Span::shortestSpan() const {
	return (1);
}

int Span::longestSpan() const {

	std::vector<int> vCopy = _vect;

	std::sort(vCopy.begin(), vCopy.end());

	int maxValue = vCopy.back() - vCopy.front();
	return (maxValue);
}

int Span::getShortestSpan() const {
	return (_minValue);
}
int Span::getLongestSpan() const {
	std::cout << _vect[0] << _vect[1] << std::endl;
	return (_maxValue);
}