#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>
# include <iostream>


//Como se define la clase stack segun cppreference
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	private:
		
	public:
		MutantStack();
		MutantStack(const MutantStack &obj);
		MutantStack &operator=(const MutantStack &obj);
		~MutantStack();

		//Permite la 
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator begin();
		const_iterator begin() const;


		iterator end();
		const_iterator end() const;


};


template <typename T, typename Container>
std::ostream& operator<<(std::ostream& out, const MutantStack<T, Container> &obj);

# include "MutantStack.tpp"

#endif