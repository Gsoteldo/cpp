#include "Array.hpp"




template<typename T>
const char *Array<T>::OutOfValue::what() const throw() {
	return ("It's out of bound");
}





template<typename T>
Array<T>::Array(): _value(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n): _value(new T[n]), _size(n) {
	if (_size == 0) {

		delete[] _value;
		_value = NULL;
	}
}

template<typename T>
Array<T>::Array(const Array &obj): _value(NULL), _size(obj._size) {
	if (_size > 0) {
		_value = new int[_size];
		for (unsigned int i = 0; i < _size ; i++) {
			_value[i] = obj._value[i];
		}
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &obj) {
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
template<typename T>
Array<T>::~Array() {
	delete[] _value;
}

template<typename T>
void Array<T>::getValue() {
	for (unsigned int i = 0; i < _size; i++) {
		std::cout << _value[i] << std::endl;
	}
}


template<typename T>
unsigned int Array<T>::size() {
	
	return (_size);
}

template<typename T>
T &Array<T>::operator[](unsigned int n) {

	if ( n >= _size)
		throw OutOfValue();

	return (this->_value[n]);
}


template<typename T>
T const &Array<T>::operator[](unsigned int n) const {
	return (this->_value[n]);
}






// template<typename T>
// std::ostream &operator<<(std::ostream& out, const T array) {
// 	for (unsigned int i = 0; i < array.size(); i++) {
// 		out << array[i] << " ";
// 	}
// 	return (out);
// }