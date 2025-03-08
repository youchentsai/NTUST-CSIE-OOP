#include<iostream>
#include<vector>

struct number {
	int num = 0;
	int counts = 0;
};

void checkDupe(std::vector<number>& numArray, int input) {
	using namespace std;
	for (int i = 0; i < numArray.size(); i++) {
		if (input == numArray[i].num) {
			numArray[i].counts++;
			return;
		}
	}
	numArray.push_back(number{ input,1 });
}

int main() {
	using namespace std;
	int input = 0;
	vector<number> outputArray;
	while (cin >> input && !cin.eof()) {
		checkDupe(outputArray, input);
	}

	//selection sort
	for (int i = 0; i < outputArray.size(); i++) {
		int max_index = i;
		for (int j = i + 1; j < outputArray.size(); j++) {
			if (outputArray[j].num > outputArray[max_index].num) {
				max_index = j;
			}
		}
		swap(outputArray[i], outputArray[max_index]);
	}

	cout << "N\tcount" << endl;

	for (number i : outputArray) {
		cout << i.num << "\t" << i.counts << endl;
	}
}