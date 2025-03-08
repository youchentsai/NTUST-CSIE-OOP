#include<iostream>
#include<cmath>
#include <iomanip> 
#define PI 3.14159265358979323864

double calculateSphereVolume(double radius) {
	long double volume = (4.0 / 3.0) * PI * powl(radius, 3);
	return round(volume * 1000000) / 1000000;//take the decimal point to sixth place
}

int main() {
	double input = 0;
	using namespace std;
	while (cin >> input && !cin.eof()) {
		cout << fixed << setprecision(6) << calculateSphereVolume(input) << endl;
	}
}