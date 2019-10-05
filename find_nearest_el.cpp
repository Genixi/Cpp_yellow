#include <iostream>
#include <set>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
	auto it1 = numbers.lower_bound(border);
	if (it1 == begin(numbers))
		return it1;
	else {
		auto it2 = prev(it1);
		if (abs(*it2 - border) > abs(*it1 - border))
				return it1;
		else
			return it2;
	}
}