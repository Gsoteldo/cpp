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
		int					_minValue;
		int					_maxValue;

	public:

		class OutOfRangeException : public std::exception {
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
		int getShortestSpan() const;
		int getLongestSpan() const;

};

#endif