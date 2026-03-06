
#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char *argv[], int argc) {
	for (int i = 1; i < argc; ++i) {
		int tmp = std::strtol(argv[i], NULL, 10);
		_vector.push_back(tmp);
		_deque.push_back(tmp);
	}
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
	_vector = obj._vector;
	_deque = obj._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
	if (this not_eq &obj) {
		_vector = obj._vector;
		_deque = obj._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

template <typename T>
T PmergeMe::Jacobsthal(size_t size) {
	 T jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	for (size_t i = 2; i < size; ++i) {
		size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next);
	}


	return (jacobsthal);
}

template <typename T>
void PmergeMe::pairElements(T& pairs, int &straggler, bool &hasStraggler) {
	for (size_t i = 0; i < _vector.size(); i += 2) {
		if (i + 1 < _vector.size()) {
			int first = _vector[i];
			int second = _vector[i + 1];
			if (first > second) {
				std::swap(first, second);
			}
			pairs.push_back(std::make_pair(first, second));
		} else {
			straggler = _vector[i];
			hasStraggler = true;
		}
	}
}

template <typename T, typename D>
void PmergeMe::splitChains(T& pendChain, T& mainChain, D pairs) {
	for (size_t i = 0; i < pairs.size(); i++)
	{
	    pendChain.push_back(pairs[i].first);
	    mainChain.push_back(pairs[i].second);
	}

}


void PmergeMe::sortVector() {
	// Sorting logic will be implemented here
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> pendChain;
	std::vector<int> mainChain;
	std::vector<int> sortedChain;
	std::vector<int>::iterator pos;
	int straggler;
	bool hasStraggler = false;

	pairElements(pairs, straggler, hasStraggler);

	splitChains(pendChain, mainChain, pairs);


	sortedChain.push_back(mainChain[0]);
	for (size_t i = 1; i < mainChain.size(); ++i)
	{
	    pos = std::lower_bound(sortedChain.begin(), sortedChain.end(), mainChain[i]);
	    sortedChain.insert(pos, mainChain[i]);
	}

	std::vector<bool> inserted(pendChain.size(), false);
	std::vector<size_t> jac = Jacobsthal<std::vector<size_t> >(pendChain.size());
	for (size_t i = 0; i < jac.size(); ++i) {
    	if (jac[i] < pendChain.size() && !inserted[jac[i]]) {
    	    int val = pendChain[jac[i]];
    	    pos = std::lower_bound(sortedChain.begin(), sortedChain.end(), val);
    	    sortedChain.insert(pos, val);
    	    inserted[jac[i]] = true;
    	}
	}
// Inserta los que faltan
	for (size_t i = 0; i < pendChain.size(); ++i) {
    	if (!inserted[i]) {
    	    int val = pendChain[i];
    	    pos = std::lower_bound(sortedChain.begin(), sortedChain.end(), val);
    	    sortedChain.insert(pos, val);
    	}
	}

	if (hasStraggler) {
		pos = std::lower_bound(sortedChain.begin(), sortedChain.end(), straggler);
		sortedChain.insert(pos, straggler);
	}
	_vector = sortedChain;

}


void PmergeMe::sortDeque() {
	// Sorting logic will be implemented here
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> pendChain;
	std::deque<int> mainChain;
	std::deque<int> sortedChain;
	std::deque<int>::iterator pos;
	int straggler;
	bool hasStraggler = false;


	pairElements(pairs, straggler, hasStraggler);

	splitChains(pendChain, mainChain, pairs);

	 sortedChain.push_back(mainChain[0]);
	 for (size_t i = 1; i < mainChain.size(); ++i)
	 {
	     pos = std::lower_bound(sortedChain.begin(), sortedChain.end(), mainChain[i]);
	     sortedChain.insert(pos, mainChain[i]);
	 }
	 std::deque<bool> inserted(pendChain.size(), false);
	 std::deque<size_t> jac = Jacobsthal<std::deque<size_t> >(pendChain.size());
	for (size_t i = 0; i < jac.size(); ++i) {
    if (jac[i] < pendChain.size() && !inserted[jac[i]]) {
        int val = pendChain[jac[i]];
        pos = std::lower_bound(sortedChain.begin(), sortedChain.end(), val);
        sortedChain.insert(pos, val);
        inserted[jac[i]] = true;
    }
}
	// Inserta los que faltan
	for (size_t i = 0; i < pendChain.size(); ++i) {
    	if (!inserted[i]) {
        	int val = pendChain[i];
        	pos = std::lower_bound(sortedChain.begin(), sortedChain.end(), val);
        	sortedChain.insert(pos, val);
    	}
	}
	if (hasStraggler) {
		pos = std::lower_bound(sortedChain.begin(), sortedChain.end(), straggler);
		sortedChain.insert(pos, straggler);
	}
	_deque = sortedChain;
}

void PmergeMe::run() {
	double durationVector = 0.0;
	double durationDeque = 0.0;

	clock_t start = clock();
	sortVector();
	clock_t end = clock();
	durationVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	sortDeque();
	end = clock();
	durationDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After(Vector): " ;
	printVector(_vector);
	std::cout << "After(Deque): " ;
	printDeque(_deque);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << durationVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << durationDeque << " us" << std::endl;
}

void PmergeMe::printVector(std::vector<int> vec) {
	if (vec.empty()) {
		vec = _vector;
	}
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(std::deque<int> deq) {
	if (deq.empty()) {
		deq = _deque;
	}
	for (size_t i = 0; i < deq.size(); ++i) {
		std::cout << deq[i] << " ";
	}
	std::cout << std::endl;
}

