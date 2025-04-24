#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

std::vector<std::string> fileInput;
std::vector<std::vector<char>> gameBoard(4, std::vector<char>());

bool dfs(int y, int x, const std::string& word, int index, std::vector<std::vector<bool>> visited) {

    if (index == word.length())
        return true;

    if (y < 0 || x < 0 || y > 3 || x > 3 || visited[y][x] || gameBoard[y][x] != word[index])
        return false;

    visited[y][x] = true;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0)
                continue;
            if (dfs(y + dy, x + dx, word, index + 1, visited)) {
                return true;
            }
        }
    }
    visited[y][x] = false; // back track
    return false;
}

int main() {
    using namespace std;
    ifstream fs;
    fs.open("words.txt");
    string fInput;
    unordered_set<char> boardLetters;
    // get all character in text file
    while (getline(fs, fInput)) {
        fileInput.push_back(fInput);
    }
    fs.close();

    // process input
    for (int i = 0; i < 4; i++) {
        string input;
        getline(cin, input);
        if (cin.eof())
            return 0;
        for (char digit : input) {
            gameBoard[i].push_back(digit);
            boardLetters.insert(digit);
        }
    }
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    for (std::string line : fileInput) {
        if (line.length() < 3)
            continue;
        // if all the letters of the line didn't contain in gameBoard, skip
        bool skip = false;
        for (char c : line) {
            if (!boardLetters.count(c)) {
                skip = true;
                break;
            }
        }
        if (skip)
            continue;
        bool found = false;
        for (int i = 0; i < 4 && !found; i++) {
            for (int j = 0; j < 4 && !found; j++) {
                // if gameBoard dont have first character ,skip
                if (gameBoard[i][j] != line[0])
                    continue;
                visited = vector<vector<bool>>(4, vector<bool>(4, false));
                if (dfs(i, j, line, 0, visited) && !found) {
                    cout << line << endl;
                    found = true;
                }
            }
        }
    }
    cout << endl;
}