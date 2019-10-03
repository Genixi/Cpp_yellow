#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

template<typename It>
void PrintRange(It range_begin, It range_end) {
	for (auto it = range_begin; it != range_end; ++it) {
		cout << *it << " ";
	}
}

void Permutations(int n) {
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		v.push_back(i);
	}
	sort(rbegin(v), rend(v));
	bool res = true;
	while(res) {
		PrintRange(begin(v), end(v));
		res = prev_permutation(begin(v), end(v));
		if (res)
			cout << endl;
	}
}

int main() {

	int n;

	cin >> n;
	Permutations(n);

	return 0;
}