#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons) {
	int first = ComputeMedianAge(begin(persons), end(persons));
	auto it = partition(begin(persons), end(persons), [](const Person& p) {return p.gender == Gender::FEMALE;});
	int second = ComputeMedianAge(begin(persons), it);
	it = partition(begin(persons), end(persons), [](const Person& p) {return p.gender == Gender::MALE;});
	int third = ComputeMedianAge(begin(persons), it);
	it = partition(begin(persons), end(persons), [](const Person& p) {return p.is_employed == false && p.gender == Gender::FEMALE;});
	int fourth = ComputeMedianAge(begin(persons), it);
	it = partition(begin(persons), end(persons), [](const Person& p) {return p.is_employed == true && p.gender == Gender::FEMALE;});
	int fifth = ComputeMedianAge(begin(persons), it);
	it = partition(begin(persons), end(persons), [](const Person& p) {return p.is_employed == false && p.gender == Gender::MALE;});
	int six = ComputeMedianAge(begin(persons), it);
	it = partition(begin(persons), end(persons), [](const Person& p) {return p.is_employed == true && p.gender == Gender::MALE;});
	int seven = ComputeMedianAge(begin(persons), it);

	cout << "Median age = " << first << endl;
	cout << "Median age for females = " << second << endl;
	cout << "Median age for males = " << third << endl;
	cout << "Median age for employed females = " << fifth << endl;
	cout << "Median age for unemployed females = " << fourth << endl;
	cout << "Median age for employed males = " << seven << endl;
	cout << "Median age for unemployed males = " << six << endl;
}

int main() {
	vector<Person> persons = {
	      {31, Gender::MALE, false},
	      {40, Gender::FEMALE, true},
	      {24, Gender::MALE, true},
	      {20, Gender::FEMALE, true},
	      {80, Gender::FEMALE, false},
	      {78, Gender::MALE, false},
	      {10, Gender::FEMALE, false},
	      {55, Gender::MALE, true},
	};
	PrintStats(persons);
	return 0;
}

