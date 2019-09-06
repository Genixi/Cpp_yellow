#include <iostream>
#include <vector>
using namespace std;

void Weight() {
	//количество блоков
	int Nums;
	//плотность блоков
	int Dens;
	//размеры блоков
	int W;
	int H;
	int D;
	unsigned long int Weight_sum = 0;
	cin >> Nums >> Dens;

	vector<vector<int> > data(Nums);
	vector<int> data_el;

	for(int i = 0; i < Nums; i++) {
		data_el.clear();
		cin >> W >> H >> D;
		data_el.push_back(W);
		data_el.push_back(H);
		data_el.push_back(D);
		data[i] = data_el;
	}

	for(int i = 0; i < Nums; i++) {
		Weight_sum = Weight_sum + data[i][0] * data[i][1] * data[i][2];
	}
	Weight_sum = Weight_sum * Dens;
	cout << Weight_sum << endl;
}

int main() {

	Weight();
	return 0;
}
