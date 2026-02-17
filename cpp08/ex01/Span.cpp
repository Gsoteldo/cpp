#include "Span.hpp"


const char* Span::OutOfRangeException::what() const throw() {
	return ("Out of Range");
}

const char* Span::NoRangeException::what() const throw() {
	return ("The container does not have enough numbers to calculate.");
}


Span::Span(): _vect(0), _maxSize(0), _size(0), _minValue(0), _maxValue(0) {}

Span::Span(unsigned int n): _vect(0), _maxSize(n), _size(0),  _minValue(0), _maxValue(0) {}

Span::Span(const Span &obj): _vect(obj._vect), _maxSize(obj._maxSize),  _minValue(obj._minValue), _maxValue(obj._maxValue) {}

Span &Span::operator=(const Span &obj) {
	if (this != &obj) {
		_vect = obj._vect;
		_maxSize = obj._maxSize;
		_minValue = obj._minValue;
		_maxValue = obj._maxValue;
	}

	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_size >= _maxSize)
		throw OutOfRangeException();
	else {
		_size++;
		_vect.push_back(n);
	}
}

int Span::shortestSpan() const {

	int shortSpan;
	int tmpSpan;

	if (_size == 0 or _size < 2) 
		throw NoRangeException();

	std::vector<int> vCopy = _vect;
	std::sort(vCopy.begin(), vCopy.end());

	shortSpan = vCopy[1] - vCopy.front();
	for (unsigned int i = 2; i < vCopy.size(); i++) {
		tmpSpan = vCopy[i] - vCopy[i - 1];
		if (tmpSpan < shortSpan)
			shortSpan = tmpSpan;
	}
	
	int minValue = shortSpan;

	return (minValue);
}

int Span::longestSpan() const {

	if (_size == 0 or _size < 2) 
		throw NoRangeException();

	std::vector<int> vCopy = _vect;

	std::sort(vCopy.begin(), vCopy.end());

	int maxValue = vCopy.back() - vCopy.front();

	return (maxValue);
}


std::vector<int> Span::getVect() const {
	return (_vect);
}

int Span::getSize() const {
	return (_size);
}

int Span::getMaxSize() const {
	return (_maxSize);
}

void Span::randomAddNumber(int total) {
	srand(time(NULL));
	for (int i = 0; i < total; i++) {
		this->addNumber(rand() % (total));
	}
}


std::ostream& operator<<(std::ostream& out, const Span &obj) {
	out << "Size: " << obj.getSize() << std::endl
		<< "Max Size: " << obj.getMaxSize() << std::endl
		<< "Longest Span: " << obj.longestSpan() << std::endl
		<< "ShortestSpan: " << obj.shortestSpan() << std::endl;

	return (out);
}

