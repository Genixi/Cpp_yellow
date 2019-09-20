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

void TestPalindrom() {

  AssertEqual(IsPalindrom("madam"), true, "madam");
  AssertEqual(IsPalindrom("level"), true, "level");
  AssertEqual(IsPalindrom("lEvel"), false, "lEvel");
  AssertEqual(IsPalindrom("Level"), false, "Level");
  AssertEqual(IsPalindrom("77778"), false, "77778");
  AssertEqual(IsPalindrom("wasitacaroracatisaw"), true, "wasitacaroracatisaw");
  AssertEqual(IsPalindrom(""), true, "");
  AssertEqual(IsPalindrom("r"), true, "r");
  AssertEqual(IsPalindrom("madam 1 madam"), true, "madam 1 madam");
  AssertEqual(IsPalindrom("madam 12 madam"), false, "madam 12 madam");
  AssertEqual(IsPalindrom("ladam 1 madam"), false, "ladam 1 madam");
  AssertEqual(IsPalindrom("madam 1 madal"), false, "madam 1 madal");
  AssertEqual(IsPalindrom("а роза упала на лапу азора"), false, "роза азора");
  AssertEqual(IsPalindrom(" madam"), false, " madam");
  AssertEqual(IsPalindrom("gentleman"), false, "gentleman");
  AssertEqual(IsPalindrom("abcca"), false, "abcca");
  AssertEqual(IsPalindrom("ab"), false, "ab");
  AssertEqual(IsPalindrom("abcdefghijklnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba"), false, "abcdefghijklnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba");
  AssertEqual(IsPalindrom("aA"), false, "aA");
  AssertEqual(IsPalindrom("kay ak"), false, "kay ak");
  AssertEqual(IsPalindrom("kay\tak"), false, "kay\tak");
  AssertEqual(IsPalindrom(" kayak"), false, " kayak");
  AssertEqual(IsPalindrom("kayak "), false, "kayak ");
  AssertEqual(IsPalindrom(" kayak"), false, "tab kayak");
  AssertEqual(IsPalindrom("kayak  "), false, "kayak tab");
  AssertEqual(IsPalindrom("\t\n \n\t"), true, "\t\n \n\t");
  AssertEqual(IsPalindrom("wasitacaroracatis"), false, "00");
  AssertEqual(IsPalindrom("sitacaroracatisaw"), false, "01");
  AssertEqual(IsPalindrom("wasitacaroracatisa"), false, "02");
  AssertEqual(IsPalindrom("asitacaroracatisaw"), false, "03");
  AssertEqual(IsPalindrom("abcbc"), false, "04");
  AssertEqual(IsPalindrom("abcca"), false, "05");
  AssertEqual(IsPalindrom("levEl"), false, "06");
  AssertEqual(IsPalindrom("leveL"), false, "07");
  AssertEqual(IsPalindrom("madam"), 1, "08");
  AssertEqual(IsPalindrom("lool"), 1, "09");
  AssertEqual(IsPalindrom("o"), 1, "09");
  AssertEqual(IsPalindrom(""), 1, "10");
  AssertEqual(IsPalindrom(" "), 1, "11");
  AssertEqual(IsPalindrom("  "), 1, "12");
  AssertEqual(IsPalindrom("top pot"), 1, "13");
  AssertEqual(IsPalindrom("o lol o"), 1, "14");
  AssertEqual(IsPalindrom(" olo "), 1, "15");
  AssertEqual(IsPalindrom("olol"), 0, "16");
  AssertEqual(IsPalindrom("motor"), 0, "17");
  AssertEqual(IsPalindrom("topo gun"), 0, "18");
  AssertEqual(IsPalindrom("olol "), 0, "19");
  AssertEqual(IsPalindrom(" lol"), 0, "20");
  AssertEqual(IsPalindrom("olo"+'\n'), 0, "21");

}

int main() {
  TestRunner runner;
  //добавьте сюда свои тесты
  runner.RunTest(TestPalindrom, "TestPalindrom");
  return 0;
}
