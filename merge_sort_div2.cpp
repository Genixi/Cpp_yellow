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
	auto second = begin(v) + v.size() / 2;
	MergeSort(begin(v), second);
	MergeSort(second, end(v));
	merge(begin(v), second, second, end(v), range_begin);
}