#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main() {

	deque<string> d;
	int n;
	int q;
	char op;
	string res = "";

	cin >> n;
	cin >> q;
	if (q == 0)
		d.push_back(to_string(n));
	else {
		d.push_front("(");
		d.push_back(to_string(n));
		d.push_back(")");
	}

	for (int i = 0; i < q; ++i) {
		cin >> op >> n;
		if (i != q - 1)
			d.push_front("(");
		if (op == '+')
			d.push_back(" + ");
		else if (op == '-')
			d.push_back(" - ");
		else if (op == '*')
			d.push_back(" * ");
		else
			d.push_back(" / ");
		d.push_back(to_string(n));
		if (i != q - 1)
			d.push_back(")");
	}

	for (auto& i : d) {
		if (i == "+" || i == "-" || i == "*" || i == "/")
			cout << " " << i << " ";
		else
			cout << i;
	}

	return 0;
}
