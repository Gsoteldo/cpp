#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		template <typename T>
		T Jacobsthal(size_t size);
		
		void sortVector();
		void sortDeque();
	public:
		PmergeMe();
		PmergeMe(char *argv[], int argc);
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();

		void run();

		void printVector(std::vector<int> vec);
		void printDeque(std::deque<int> deq);
};

#endif