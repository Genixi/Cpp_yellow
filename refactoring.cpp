#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


class Person {
public:
	Person(const string& name, const string& job) : Name_(name), Job_(job) {}

	virtual void Walk(const string& str) const = 0;

	string getName() const {
		return Name_;
	}

	string getJob() const {
		return Job_;
	}

private:
	const string Name_;
	const string Job_;
};


class Student : public Person {
public:
	Student(const string& name, const string& favouriteSong) : Person(name, "Student"), FavouriteSong_(favouriteSong) {}

	void Walk(const string& destination) const override {
		cout << "Student: " << getName() << " walks to: " << destination << endl;
		cout << "Student: " << getName() << " sings a song: " << FavouriteSong_ << endl;
	}

    void Learn() const {
        cout << "Student: " << getName() << " learns" << endl;
    }

    void SingSong() const {
        cout << "Student: " << getName() << " sings a song: " << FavouriteSong_ << endl;
    }

private:
    const string FavouriteSong_;
};


class Teacher : public Person {
public:
	Teacher(const string& name, const string& subject) : Person(name, "Teacher"), Subject_(subject) {}

	void Walk(const string& destination) const override {
	        cout << "Teacher: " << getName() << " walks to: " << destination << endl;
	    }

    void Teach() const {
        cout << "Teacher: " << getName() << " teaches: " << Subject_ << endl;
    }

private:
    const string Subject_;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name, "Policeman") {}

    void Walk(const string& destination) const override {
            cout << "Policeman: " << getName() << " walks to: " << destination << endl;
        }

    void Check(Person& p) const {
    	cout << "Policeman: " << getName() << " checks" << p.getJob() << ". " << p.getJob()
    			<< "'s name is: " << p.getName() << endl;
    }
};

void VisitPlaces(Person& t, vector<string> places) {
    for (const auto& p : places) {
        t.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
