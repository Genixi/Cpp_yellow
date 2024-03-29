#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <exception>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u
       << " hint: " << hint;
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
	// Вы можете вставлять сюда различные реализации функции,
	// чтобы проверить, что ваши тесты пропускают корректный код
	// и ловят некорректный
	return 1;
}

void TestSqr() {
	AssertEqual(GetDistinctRealRootCount(0, 5, 10), 1, "one root 0  5 10");
	AssertEqual(GetDistinctRealRootCount(0, 5, -10), 1, "one root 0 5 -10");
	AssertEqual(GetDistinctRealRootCount(0, 5, 0), 1, "one root 0 5 0");
	AssertEqual(GetDistinctRealRootCount(5, 0, 10), 0, "0 roots 5 0 10");
	AssertEqual(GetDistinctRealRootCount(5, 0, -10), 2, "two roots 5 0 -10");
	AssertEqual(GetDistinctRealRootCount(5, 2, 0), 2, "two roots 5 2 0");
	AssertEqual(GetDistinctRealRootCount(-5, 0, 0), 1, "one root -5 0 0");
	AssertEqual(GetDistinctRealRootCount(5, 2, 7), 0, "zero roots 5 2 7");
	AssertEqual(GetDistinctRealRootCount(5, 12, 7), 2, "zero roots 5 12 7");
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "zero roots 0 0 1");
	AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1, "one roots 0 1 1");
	AssertEqual(GetDistinctRealRootCount(1, 3, 1), 2, "two roots 1 3 1");
	AssertEqual(GetDistinctRealRootCount(1, 1, 1), 0, "zero roots 1 1 1");
}

int main() {
  TestRunner runner;
  //добавьте сюда свои тесты
  runner.RunTest(TestSqr, "TestSqr");
  return 0;
}
