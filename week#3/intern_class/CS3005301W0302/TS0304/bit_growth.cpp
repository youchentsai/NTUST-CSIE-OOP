#include<iostream>
#include<cmath>
#include<vector>

double getMaxLogInt(int Y) {
	int k = 4 * pow(2, (Y - 1900) / 10);//calculate bits
	//return log(process speed(max Interger CPU can handle))
	return k * log(2);// log(2^k) = k * log(2)
}

int findMaxFactorial(double maxLogInt) {
	double logFactorial = 0.0;
	int N = 1;
	//log(1*2*3*4*5*6*7...) = log(1)+log(2)+log(3)+...
	while (true) {
		logFactorial += log(N);
		if (logFactorial > maxLogInt) break;
		N++;
	}
	return N - 1; //log(N!) > maxLogInt => log(N-1) < maxLogInt
}


int main() {
	using namespace std;
	int year = 0;
	while (cin >> year && !cin.eof()) {
		double maxlogInt = getMaxLogInt(year);
		int maxFactorial = findMaxFactorial(maxlogInt);
		cout << maxFactorial << endl;
	}
}