#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
	auto neg = find_if(begin(numbers), end(numbers),
			[](const int& num) {
		return num < 0;
	});
	if (neg == end(numbers)) {
		auto it = end(numbers);
		while (it != begin(numbers)) {
			--it;
			cout << *it << " ";
		}
	} else {
		auto it = neg;
		while (it != begin(numbers)) {
			--it;
			cout << *it << " ";
		}
	}
}