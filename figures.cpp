#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <memory>
#include <sstream>


using namespace std;

class Figure {
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
	Triangle(const double& a, const double& b, const double& c) : a_(a), b_(b), c_(c) {}

	string Name() const override {
		return "TRIANGLE";
	}
	double Perimeter() const override {
		return a_ + b_ + c_;
	}
	double Area() const override {
		double p = (a_ + b_ + c_) / 2;
		return sqrt(p * (p - a_) * (p - b_) * (p - c_));
	}

private:
	double a_;
	double b_;
	double c_;
};

class Rect : public Figure {
public:
	Rect(const double& a, const double& b) : a_(a), b_(b) {}

	string Name() const override {
		return "RECT";
	}
	double Perimeter() const override {
		return 2 * a_ + 2 * b_;
	}
	double Area() const override {
		return a_ * b_;
	}

private:
	double a_;
	double b_;
};

class Circle : public Figure {
public:
	Circle(const double& r) : r_(r) {}

	string Name() const override {
		return "CIRCLE";
	}
	double Perimeter() const override {
		return 2 * 3.14 * r_;
	}
	double Area() const override {
		return r_ * r_ * 3.14;
	}

private:
	double r_;
};

shared_ptr<Figure> CreateFigure(istringstream& arg) {
	shared_ptr<Figure> res;
	string opt;
	arg >> opt;
	if (opt == "RECT") {
		double a, b;
		arg >> a >> b;
		res = make_shared<Rect>(a, b);
	} else if (opt == "TRIANGLE") {
		double a, b, c;
		arg >> a >> b >> c;
		res = make_shared<Triangle>(a, b, c);
	} else {
		double r;
		arg >> r;
		res = make_shared<Circle>(r);
	}

	return res;
}

int main() {
	vector<shared_ptr<Figure>> figures;

	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		} else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
	            << current_figure->Name() << " "
				<< current_figure->Perimeter() << " "
				<< current_figure->Area() << endl;
			}
		}
	 }

	 return 0;
}
