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

void TestPerson() {
	Person person;

	AssertEqual(person.GetFullName(2019), "Incognito", "no change");
	person.ChangeLastName(2017, "Pots");
	AssertEqual(person.GetFullName(2017), "Pots with unknown first name", "test 2017 last name only");
	person.ChangeFirstName(2015, "Vitalik");
	AssertEqual(person.GetFullName(2016), "Vitalik with unknown last name", "test 2016");
	AssertEqual(person.GetFullName(2017), "Vitalik Pots", "test 2017");
	person.ChangeFirstName(2014, "Zhenya");
	AssertEqual(person.GetFullName(2014), "Zhenya with unknown last name", "double name change 1");
	AssertEqual(person.GetFullName(2017), "Vitalik Pots", "test double name change 2");
	person.ChangeLastName(2018, "Norm");
	AssertEqual(person.GetFullName(2017), "Vitalik Pots", "test double name change 3");
	AssertEqual(person.GetFullName(2018), "Vitalik Norm", "test double name change 4");
}

int main() {
  TestRunner runner;
  //добавьте сюда свои тесты
  runner.RunTest(TestPerson, "TestPerson");
  return 0;
}
