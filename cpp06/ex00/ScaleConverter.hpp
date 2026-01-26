#ifndef SCALECONVERTER_HPP
# define SCALECONVERTER_HPP

# include <iostream>
# include <string>

# define IS_PRINTABLE(c) (c >= 32 && c <= 126)



class ScaleConverter {
	private:
		
	public:
		ScaleConverter();
		ScaleConverter(const ScaleConverter &obj);
		ScaleConverter &operator=(const ScaleConverter &obj);
		~ScaleConverter();

		static int detectType(const std::string &input);
		static void convert(const std::string &input);
		
};


#endif 