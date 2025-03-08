#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<sstream>

std::string formatted(double number, int total_length, int decimal_length, char letter) {
	using namespace std;
	stringstream ss;
	string output = "";
	if (total_length == 0) return"";
	//unconditionally discarded
	int factor = pow(10, decimal_length);
	if (number >= 0)
		number = floor(number * factor) / factor;
	else {
		number = floor(fabs(number) * factor) / factor * -1;
	}
	ss << fixed << setprecision(decimal_length) << number;
	output = ss.str();
	//fill the rest of space with letter
	if (total_length > output.length()) {
		int outputLength = output.length();
		for (int i = 0; i < total_length - outputLength; i++) {
			output.insert(output.begin(), letter);
		}
	}

	return output;
}

int main() {
	using namespace std;
	

	while (true) {
		if (cin.eof()) {
			break;
		}
		double number = 0;
		int total_length = 0;
		int decimal_length = 0;
		char letter = ' ';
		while (cin >> number >> total_length >> decimal_length) {
			cin.ignore();
			// 4th input include space
			if (cin >> letter) {

			}
			if (cin.peek() == '\n')
				break;
		}
		cout << formatted(number, total_length, decimal_length, letter) << endl;
	}
	return 0;
}