#include "iter.hpp"

int main() {
	int array[4] = {1 ,2, 3, 4 };

	::iter(array, 4 , ::printArray<int>);
}