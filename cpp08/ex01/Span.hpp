#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

class Span {
	private:
		std::vector<int>	_vect;
		unsigned int		_maxSize;
		unsigned int		_size;
		int					_minValue;
		int					_maxValue;

	public:

		class OutOfRangeException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NoRangeException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		Span();
		Span(unsigned int n);
		Span(const Span &obj);
		Span &operator=(const Span &obj);
		~Span();

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;
		void randomAddNumber(int total);

		std::vector<int> getVect() const;
		int getSize() const;
		int getMaxSize() const;

};

	std::ostream& operator<<(std::ostream& out, const Span &obj);
	void randomAddNumber(Span &span, int total);
#endif