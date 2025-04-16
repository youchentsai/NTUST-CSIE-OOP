#include<iostream>
#include<string>
#include<iomanip>
#include<vector>

int main() {
	using namespace std;
	while (!cin.eof()) {
		int employeeNum = 0;
		string input;
		cin >> employeeNum;
		//initial vector
		vector<vector<string>> employeeInfo(employeeNum, vector<string>(3, ""));
		vector<int> max_length;

		for (int i = 0; i < employeeNum; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> employeeInfo[i][j];
			}
		}

		//find longest string in each employeeInfo
		for (int i = 0; i < 3; i++) {
			int max_index = 0;
			for (int j = 0; j < employeeNum; j++) {
				if (j + 1 != employeeNum && employeeInfo[j][i].length() < employeeInfo[j + 1][i].length()) {
					max_index = j + 1;
				}
			}
			max_length.push_back(employeeInfo[max_index][i].length());
		}

		for (int i = 0; i < employeeNum; i++) {
			for (int j = 0; j < 3; j++) {
				cout << setw(max_length[j]) << employeeInfo[i][j];
				if (j != 2) {
					cout << "|  ";
				}
			}
			cout << endl;
		}

	}

}