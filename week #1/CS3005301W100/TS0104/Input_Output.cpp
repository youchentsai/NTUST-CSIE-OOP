#include<iostream>
#include<string>
#include<iomanip>

int main() {
	using namespace std;

	string input;
	while (cin >> input && !cin.eof()) {
		if (input.length() < 10) {
			cout << setw(10 - input.length()) << " " << input << endl;
			continue;
		}
		cout << input << endl;
	}
}