#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

class Array {
	private:
		int *_value;
		unsigned int _size;
		
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &obj);
		Array &operator=(const Array &obj);
		~Array();

		int  &operator[](unsigned int n);

		unsigned int size();
		void getValue();
	};
	


#endif