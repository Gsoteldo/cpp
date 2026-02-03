#include "Array.hpp"

Array::Array(): _value(NULL), _size(0) {}

Array::Array(unsigned int n): _value(new int[n]), _size(n) {
	if (_size == 0) {

		delete[] _value;
		_value = NULL;
	}
}

Array::Array(const Array &obj): _value(NULL), _size(obj._size) {
	if (_size > 0) {
		_value = new int[_size];
		for (unsigned int i = 0; i < _size ; i++) {
			_value[i] = obj._value[i];
		}
	}
}

Array &Array::operator=(const Array &obj) {
	if (this != &obj) {
		_size = obj._size;
		if (_value)
			delete[] _value;

		if (_size > 0) {
			_value = new int[_size];
		} else {
			_value = NULL;
		}

		for (unsigned int i = 0; i < _size ; i++) {
			_value[i] = obj._value[i];
		}
	}
	return (*this);
}

Array::~Array() {
	delete[] _value;
}

void Array::getValue() {
	for (unsigned int i = 0; i < _size; i++) {
		std::cout << _value[i] << std::endl;
	}
}

unsigned int Array::size() {
	
	return (_size);
}