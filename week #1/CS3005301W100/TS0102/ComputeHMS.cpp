#include<iostream>
#include<string>

int main() {
	unsigned long long int input = 0;
	using namespace std;
	while (cin >> input && !cin.eof()) {
		unsigned long long int hours = 0, mins = 0, secs = 0;
		hours = input / 3600;
		mins = (input % 3600) / 60;
		secs = input % 60;
		cout << hours << " hours " << mins << " minutes and " << secs << " seconds" << endl;
	}

}