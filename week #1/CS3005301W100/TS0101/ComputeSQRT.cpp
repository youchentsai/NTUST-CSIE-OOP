#include<iostream>
#include<cmath>
#include <iomanip> 

double Babylonian(double input) {
	double guess = 0, previous_guess = 0, root = 0;
	guess = input / 2;
	do {
		previous_guess = guess;
		root = input / guess;
		guess = (guess + root) / 2;
	} while (fabs(guess - previous_guess) > 0.01);
	return (round(guess * 100) / 100); //round to 2 decimal place
}

int main() {
	using namespace std;
	double input = 0;
	while (cin >> input && !cin.eof()) {
		cout << fixed << setprecision(2) << Babylonian(input) << endl;
	}
}