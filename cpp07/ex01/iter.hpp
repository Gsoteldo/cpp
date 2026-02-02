#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void printArray(T const &value) {
	std::cout << value <<std::endl;
}




template <typename T>
void iter(T *address, const int length, void(*f)(T const &)) {
	if (!address)
		return ;	

	for (int i = 0; i < length; i++) {
		f(address[i]);
	}
}

#endif