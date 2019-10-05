#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

string FindName(const map<int, string>& names, int year) {
	string name;
	auto it = names.upper_bound(year);
	if (it != names.begin()) {
		name = (--it)->second;
	}
	return name;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  FirstName[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  SecondName[year] = last_name;
  }
  string GetFullName(int year) {
	  const string fname = FindName(FirstName, year);
	  const string sname = FindName(SecondName, year);

	  if (fname.empty() && sname.empty()) {
	  	  return "Incognito";
	  } else if(!fname.empty() && !sname.empty()) {
	  	  return fname + " " + sname;
	  } else if(!fname.empty()) {
	  	  return fname + " with unknown last name";
	  } else {
	  	  return sname + " with unknown first name";
	  }
  }
private:
  map <int, string> FirstName;
  map <int, string> SecondName;
};