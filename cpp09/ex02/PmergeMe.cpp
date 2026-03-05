
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj) {
	_vector = obj._vector;
	_deque = obj._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
	if (this != &obj) {
		_vector = obj._vector;
		_deque = obj._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}