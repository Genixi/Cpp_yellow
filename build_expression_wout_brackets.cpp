#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main() {

	char ch = '!';
	deque<string> d;
	int n;
	int q;
	char op;
	string res = "";

	cin >> n;
	cin >> q;
	d.push_back(to_string(n));

	for (int i = 0; i < q; ++i) {
		cin >> op >> n;
		if (op == '+') {
			d.push_back("+");
			ch = '+';
		} else if (op == '-') {
			d.push_back("-");
			ch = '-';
		} else if (op == '*') {
			if (i != 0 && (ch == '+' || ch == '-')) {
				d.push_front("(");
				d.push_back(")");
			}
			d.push_back("*");
			ch = '*';
		} else {
			if (i != 0 && (ch == '+' || ch == '-')) {
				d.push_front("(");
				d.push_back(")");
			}
			d.push_back("/");
			ch = '/';
		}
		d.push_back(to_string(n));
	}

	for (auto& i : d) {
		if (i == "+" || i == "-" || i == "*" || i == "/")
			cout << " " << i << " ";
		else
			cout << i;
	}

	return 0;
}
