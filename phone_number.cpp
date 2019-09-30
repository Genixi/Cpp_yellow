#include <string>
#include <sstream>

using namespace std;

#include "phone_number.h"

PhoneNumber::PhoneNumber(const string& international_number) {
	stringstream str(international_number);
	string country_code, city_code, local_number;
	if (str) {
		getline(str, country_code, '-');
		getline(str, city_code, '-');
		getline(str, local_number, '\n');
	}

	if (country_code[0] != '+')
		throw invalid_argument("no +");
	if (country_code.length() < 2)
		throw invalid_argument("country length incorrect");
	country_code = country_code.substr(1);
	if (city_code.length() == 0)
		throw invalid_argument("city length incorrect");
	if (local_number.length() == 0)
		throw invalid_argument("local length incorrect");

	country_code_ = country_code;
	city_code_ = city_code;
	local_number_ = local_number;
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_+ "-" + city_code_ + "-" + local_number_;
}