#include<iostream>
#include<string>
#include<vector>
#include<cmath>


int main() {
	using namespace std;
	string input;

	while (cin >> input && !cin.eof()) {
		int n = 1;

		//find n
		while (true) {
			if (input.size() > pow(n - 1, 2) && input.size() <= pow(n, 2))
				break;
			n++;
		}
		//initial vector
		vector<vector<string>> squarArray(n,vector<string>(n,""));
		for (int i = 0; i < input.length(); i++) {
			squarArray[i / n][i % n] = input[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!squarArray[j][i].empty()) {
					cout << squarArray[j][i];
				}
			}
			cout << endl;
		}

	}

}