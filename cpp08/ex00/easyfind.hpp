#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <iostream>
# include <exception>
# include <list>
# include <deque>


class NumberNotFoundException : public std::exception {
		public:
			virtual const char* what() const throw();
		};


template<typename T>
void easyfind(T &cont, int n);

#include "easyfind.tpp"

#endif