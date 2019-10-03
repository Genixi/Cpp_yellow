#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& v) {
	sort(begin(v), end(v));
	auto last = unique(begin(v), end(v));
	v.erase(last, end(v));
}