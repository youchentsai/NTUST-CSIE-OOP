#include<iostream>
#include<iomanip>

int main() {
	using namespace std;
	double income,output;
	while (cin >> income && !cin.eof()) {
		if (income < 750) {
			output = income * 0.01;
		}
		else if (income >= 750 && income < 2250) {
			output = 7.5 + (income - 750) * 0.02;
		}
		else if (income >= 2250 && income < 3750) {
			output = 37.5 + (income - 2250) * 0.03;
		}
		else if (income >= 3750 && income < 5250) {
			output = 82.5 + (income - 3750) * 0.04;
		}
		else if (income >= 5250 && income < 7000) {
			output = 142.5 + (income - 5250) * 0.05;
		}
		else {
			output = 230 + (income - 7000) * 0.06;
		}

		cout << fixed << setprecision(2) << output << endl;
	}

}