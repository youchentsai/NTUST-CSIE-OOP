#include<iostream>
#include<vector>
#include<cmath>
#include<string>


struct BigInt
{
	std::vector<int> digit;

	void clearInput() {
		digit.clear();
	}
};

BigInt Add(const BigInt& lhs, const BigInt& rhs) {
	BigInt result;
	int carry_flag = 0, tempResult;

	int length = std::max(lhs.digit.size(), rhs.digit.size());

	for (int i = 0; i < length; i++) {
		int leftDigit = (i < lhs.digit.size()) ? lhs.digit[i] : 0;
		int rightDigit = (i < rhs.digit.size()) ? rhs.digit[i] : 0;

		tempResult = leftDigit + rightDigit + carry_flag;
		carry_flag = tempResult / 10;
		result.digit.push_back(tempResult % 10);
	}

	if (carry_flag > 0) {
		result.digit.push_back(carry_flag);
	}

	return result;
}

int main() {
	using namespace std;


	int n = 0;
	cin >> n;

	BigInt a, b;
	string InputA, InputB;
	vector<char> num_A, num_B;

	for (int i = 0; i < n; i++) {
		//initial vector
		num_A.clear();
		num_B.clear();
		a.digit.clear();
		b.digit.clear();

		cin >> InputA >> InputB;
		for (int i = 0; i < InputA.length(); i++) {
			num_A.push_back(InputA[i]);
		}
		for (int i = 0; i < InputB.length(); i++) {
			num_B.push_back(InputB[i]);
		}

		//convert into number
		bool isError = false;
		for (int j = InputA.length() - 1; j >= 0; j--) {
			if (num_A[j] >= 48 && num_A[j] <= 57) {
				a.digit.push_back(num_A[j] - '0');
			}
			else {
				isError = true;
				break;
			}

		}

		for (int j = InputB.length() - 1; j >= 0; j--) {
			if (num_B[j] >= 48 && num_B[j] <= 57) {
				b.digit.push_back(num_B[j] - '0');
			}
			else {
				isError = true;
				break;
			}
		}
		//find invalid error
		if (isError) {
			a.digit.clear();
			b.digit.clear();
			cout << "Not a valid number, please try again." << endl;
			continue;
		}

		//find bigger number & make two vector have same length
		int length = max(a.digit.size(), b.digit.size());
		while (a.digit.size() < length) {
			a.digit.push_back(0);
		}
		while (b.digit.size() < length) {
			b.digit.push_back(0);
		}
		
		BigInt result = Add(a, b);

		for (int i = result.digit.size() - 1; i >= 0; i--) {
			cout << result.digit[i];
		}
		cout << endl;
	}


}