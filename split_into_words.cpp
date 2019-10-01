#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> res;
	auto start = begin(s);
	for (auto it = begin(s); it != end(s); ++it) {
		auto sp = find(it, end(s), ' ');
		if (sp != end(s)) {
			res.push_back(string(start, sp));
			it = sp;
			start = ++it;
		}
	}
	res.push_back(string(start, end(s)));
	return res;
}