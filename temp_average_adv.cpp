#include <iostream>
#include <vector>
using namespace std;

void Temperature() {
	int N;
	cin >> N;
	vector<int> data(N);
	for(int i = 0; i < N; i++) {
		cin >> data[i];
	}

	double mean = 0;
	for(int i = 0; i < N; i++) {
		mean += data[i];
	}
	mean /= N;

	int count = 0;
	vector<int> res;
	for (int j = 0; j < N; j++) {
		if (data[j] > mean) {
			res.push_back(j);
			count++;
		}
	}

	cout << count<< endl;
	for (int i = 0; i < count; i++) {
		cout << res[i] << " ";
	}
}

int main() {

	Temperature();
	return 0;
}
