#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
	string str = {prefix};
	char next = prefix + 1;
	string str2 = {next};
	auto it = lower_bound(range_begin, range_end, str);
	auto it2 = upper_bound(range_begin, range_end, str2);
	pair<RandomIt, RandomIt> res(it, it2);
	return res;
}