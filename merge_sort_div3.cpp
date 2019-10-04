#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
	if (range_end - range_begin < 2) {
		return ;
	}
	vector<typename RandomIt::value_type> v(range_begin, range_end);
	auto second = begin(v) + v.size() / 3;
	auto third = second + v.size() / 3;
	MergeSort(begin(v), second);
	MergeSort(second, third);
	MergeSort(third, end(v));
	vector<typename RandomIt::value_type> v2;
	merge(begin(v), second, second, third, back_inserter(v2));
	merge(begin(v2), end(v2), third, end(v), range_begin);
}