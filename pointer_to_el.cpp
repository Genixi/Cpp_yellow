#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <string>
#include <stdexcept>
using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k) {
	if (m.count(k) == 0) {
		throw runtime_error("no such key in dict");
	}
	return m[k];
}