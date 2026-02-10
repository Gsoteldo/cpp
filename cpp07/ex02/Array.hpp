#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <exception>

template<typename T>
class Array {
	private:
		T *_value;
		unsigned int _size;
		
	public:
		class OutOfValue : public std::exception {
			public:
				virtual const char* what() const throw();
			};
			
		Array();
		Array(unsigned int n);
		Array(const Array &obj);
		Array &operator=(const Array &obj);
		~Array();

		T const &operator[](unsigned int n) const;
		T &operator[](unsigned int n);

		unsigned int size() const;
		void getValue();
	};

	template<typename T>
	std::ostream &operator<<(std::ostream& out, const Array<T> &array); 
	
# include "Array.tpp"

#endif