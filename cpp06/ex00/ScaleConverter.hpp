#ifndef SCALECONVERTER_HPP
# define SCALECONVERTER_HPP

# include <iostream>
# include <string>
#include <cstdlib>
# include <climits>
# include <cfloat>
# include <iomanip>

# define IS_PRINTABLE(c) (c >= 32 && c <= 126)
# define INT_OUT_OF_RANGE(i) (i < INT_MIN || i > INT_MAX)
# define FLOAT_OUT_OF_RANGE(f) (f < -FLT_MAX || f > FLT_MAX)
# define DOUBLE_OUT_OF_RANGE(d) (d < -DBL_MAX || d > DBL_MAX)


class ScaleConverter {
	private:
		
	public:
		ScaleConverter();
		ScaleConverter(const ScaleConverter &obj);
		ScaleConverter &operator=(const ScaleConverter &obj);
		~ScaleConverter();

		static bool isPseudoLiteral(std::string input);
		static int detectType(const std::string &input);
		static void printChar(const std::string &input, int type);
		static void printInt(const std::string &input, int type);
		static void printFloat(const std::string &input, int type);
		static void printDouble(const std::string &input, int type);
		static void printAll(const std::string &input, int type);
		static void convert(const std::string &input);

};


#endif 