#include<iostream>
#include<string>
#include<vector>
#include<fstream>

void getHighScores(std::vector<std::string>& players, std::vector<int>& scores) {
	using namespace std;
	fstream fs;
	string filename = "scores.txt", fileInput = "";
	fs.open(filename);

	//read file
	while (getline(fs, fileInput)) {
		try {
			scores.push_back(stoi(fileInput));
		}
		catch (invalid_argument&) {
			players.push_back(fileInput);
		}
	}
	fs.close();
	

	//selection sort
	for (int i = 0; i < scores.size(); i++) {
		int max_index = i;
		for (int j = i + 1; j < scores.size(); j++) {
			if (scores[j] > scores[max_index])
				max_index = j;
		}

		//swaps element
		swap(scores[i], scores[max_index]);
		swap(players[i], players[max_index]);
	}

	//delete non-top 3 player
	while (scores.size() > 3) {
		scores.pop_back();
		players.pop_back();
	}
}

int main() {
	using namespace std;
	vector<string> players;
	vector<int> scores;
	getHighScores(players, scores);

	for (int i = 0; i < 3; i++) {
		cout << players[i] << endl;
		cout << scores[i] << endl;
	}

	return 0;
}