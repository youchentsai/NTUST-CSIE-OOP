#include<iostream>
#include<cmath>
#include<string>
#include<vector>

double CalcDeviation(std::vector<double> numArray, double average) {
	double sum = 0;
	for (double i : numArray) {
		sum += pow(i - average, 2);
	}
	return sqrt(sum / numArray.size());
}

double CalcAverage(std::vector<double> numArray) {
	double sum = 0, average = 0;
	for (double i : numArray) {
		sum += i;
	}
	average = sum / numArray.size();
	return(average);
}

int main() {
	using namespace std;

	while (true) {
		vector<double> numArray;
		double average = 0, deviation = 0;
		double input = 0;

		if (cin.eof()) {
			break;
		}

		while (cin >> input) {
			numArray.push_back(input);
			if (cin.peek() == '\n') {
				break;
			}
		}

		//remove 1st element in vector
		numArray.erase(numArray.begin());

		average = CalcAverage(numArray);
		deviation = CalcDeviation(numArray, average);

		printf("Average:%g", average);
		cout << "\t";
		printf("Standard deviation:%g", deviation);
		cout << endl;
	}
	return 0;
}