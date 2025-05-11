

#include <iostream>
#include <string>
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {

	private:
		std::string name;


	public:
		Zombie(std::string name);
		~Zombie();
		void announce();


};


#endif