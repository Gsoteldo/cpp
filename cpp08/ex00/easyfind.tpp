#include "easyfind.hpp"

const char* NumberNotFoundException::what() const throw(){
	return ("Number not found in container");
}

template<typename T>
void easyfind(T &cont, int n) {
	if (cont.empty()) {
		std::cout << "Container is empty" << std::endl;
		return ;
	}
	typename T::iterator check = find(cont.begin(), cont.end(), n);

	if (check == cont.end())
		throw NumberNotFoundException();

	int index = std::distance(cont.begin(), check);

	std::cout << "The number is in " << index << " index";
	std::cout << std::endl;

	return ;
}