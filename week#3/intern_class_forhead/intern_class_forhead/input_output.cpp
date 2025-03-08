#include<iostream>
#include<vector>
#include<string>
#include<sstream>

int main() {
	using namespace std;
	double number = 0;
	int total_length = 0;
	int decimal_length = 0;
	char letter = ' ';

	while (true) {
		if (cin.eof()) {
			break;
		}
		vector<string> inputArray;
		string input;
		while (cin >> input) {
			inputArray.push_back(input);
		}
		number = stod(inputArray[0]);
		total_length = stoi(inputArray[1]);
		decimal_length = stoi(inputArray[2]);
		if (inputArray.size() != 3) {
			letter = inputArray[3][0];
		}
	}

}