#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	vector<T> res;
	for (auto it = begin(elements); it != end(elements); ++it) {
		if (*it > border)
			res.push_back(*it);
	}
	sort(begin(res), end(res));
	return res;
}