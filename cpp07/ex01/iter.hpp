#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>



class Awesome
{
	private:
		int _n;
	public:
		Awesome(void): _n(42) {return;}

		int	get_n() const {return (this->_n);}
		Awesome & operator=(const Awesome& rhs);
		bool operator==(Awesome const & rhs) const;
		bool operator!=(Awesome const & rhs) const;
		bool operator>(Awesome const & rhs) const;
		bool operator<(Awesome const & rhs) const;
		bool operator>=(Awesome const & rhs) const;
		bool operator<=(Awesome const & rhs) const;

};
/* << overlaod */
std::ostream & operator<<(std::ostream & os, const Awesome &a) { os << a.get_n(); return (os);}
/* operators overloads */
Awesome & Awesome::operator=(const Awesome& a) {this->_n = a._n; return (*this); }
bool Awesome::operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
bool Awesome::operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
bool Awesome::operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
bool Awesome::operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
bool Awesome::operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
bool Awesome::operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }




template <typename T>
void printArray(T const &value) {
	std::cout << value <<std::endl;
}

template <typename T>
void printer(T const &value) {
	std::cout << value <<std::endl;
}

template <typename T>
void iter(T *address, const int length, void(*f)(T &)) {
	if (!address)
		return ;	

	for (int i = 0; i < length; i++) {
		f(address[i]);
	}
}

template <typename T>
void iter(const T *address, const int length, void(*f)(const T &)) {
	if (!address || !f)
		return ;

	if (length <= 0)
		return ;

	for (int i = 0; i < length; i++) {
		f(address[i]);
	}
}

#endif