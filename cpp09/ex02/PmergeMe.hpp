#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <climits>
# include <cstdlib>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		template <typename T>
		T Jacobsthal(size_t size);

		template <typename T>
		void pairElements(T& pairs, int &straggler, bool &hasStraggler);

		template <typename T, typename D>
		void splitChains(T& pendChain, T& mainChain, D pairs);

		
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