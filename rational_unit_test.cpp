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

void TestRational() {
  Rational rational;

  AssertEqual(rational.Numerator(), 0, "default numerator");
  AssertEqual(rational.Denominator(), 1, "default denominator");
  Rational rational1(2, 4);
  AssertEqual(rational1.Numerator(), 1, "test 1");
  AssertEqual(rational1.Denominator(), 2, "test 2");
  Rational rational2(-3, 9);
  AssertEqual(rational2.Numerator(), -1, "test 3");
  AssertEqual(rational2.Denominator(), 3, "test 4");
  Rational rational3(-7, -21);
  AssertEqual(rational3.Numerator(), 1, "test 5");
  AssertEqual(rational3.Denominator(), 3, "test 6");
  Rational rational4(0, 21);
  AssertEqual(rational4.Numerator(), 0, "test 7");
  AssertEqual(rational4.Denominator(), 1, "test 8");

}

int main() {
  TestRunner runner;
  //добавьте сюда свои тесты
  runner.RunTest(TestRational, "TestRational");
  return 0;
}
