#include<iostream>
#include<fstream>
#include<vector>
#include<string>


struct grades {
	int num = 0;
	int count = 0;
};

void checkDupe(std::vector<grades>& gradeArray, int input) {
	for (int i = 0; i < gradeArray.size(); i++) {
		if (gradeArray[i].num == input) {
			gradeArray[i].count++;
			return;
		}
	}
}

int main() {
	using namespace std;
	string input;
	ifstream fp;
	ofstream fs;
	fp.open("grade.txt");
	fs.open("grades.Output");
	while (getline(fp, input)) {
		vector<grades> outputArray;
		//initial vector 0~5
		for (int i = 0; i <= 5; i++) {
			outputArray.push_back(grades{ i ,0 });
		}
		if (cin.eof()) {
			break;
		}
		for (int i = 0; i < input.length(); i++) {
			if (input[i] != ' ') {
				checkDupe(outputArray, input[i] - '0');//input[i] - '0' convert to int
			}
		}
		
		for (int i = 0; i < outputArray.size(); i++) {
			fs << outputArray[i].count << " " << "grade(s) of " << outputArray[i].num << endl;
		}
	}

	fs.close();
	fp.close();
}
