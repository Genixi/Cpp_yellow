#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
using namespace std;

template <typename T> T Sqr(T x);
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p);
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m);
template <typename T> vector<T> Sqr(const vector<T>& v);

template <typename T>
T Sqr(T x) {
	return x * x;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p) {
	First f = Sqr(p.first);
	Second s = Sqr(p.second);
	return make_pair(f, s);
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m) {
	map<Key, Value> res;
	for (const auto& x : m) {
		res[x.first] = Sqr(x.second);
	}
	return res;
}

template <typename T>
vector<T> Sqr(const vector<T>& v) {
	vector<T> res;
	for (const auto& i : v) {
		res.push_back(Sqr(i));
	}
	return res;
}