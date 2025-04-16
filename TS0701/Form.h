#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Form {
private:
    string inputword;
    string fileName;
    vector<string> answer;

public:
    void SetInputWord(string inputWord); // set input
    void ProcessInputWord();             // process input
    void SetFileName(string fileName);   // set file name
    void Load_CompareWord();             // read-in data and compare
    void PrintFoundWords();              // print answers
};

void Form::SetFileName(string _fileName) {
    fileName = _fileName;
}

void Form::SetInputWord(string _inputWord) {
    inputword = _inputWord;
}

void Form::ProcessInputWord() {
    for (int i = 0; i < inputword.length(); i++) {
        if (isupper(inputword[i])) {
            inputword[i] = tolower(inputword[i]);
        }
    }
}

void Form::Load_CompareWord() {
    ifstream fs;
    vector<string> result;
    fs.open(fileName);
    if (fs.is_open()) {
        unordered_map<char, int> InputWordMap;
        for (int i = 0; i < inputword.length(); i++) {
            InputWordMap[inputword[i]]++;
        }
        string fileInput;
        while (getline(fs, fileInput)) {
            // skip too long words
            if (fileInput.length() > inputword.length()) {
                continue;
            }
            bool isValid = true;
            unordered_map<char, int> fileInputWordMap;
            for (int i = 0; i < fileInput.length(); i++) {
                fileInputWordMap[fileInput[i]]++;
            }

            for (pair<char, int> subPair : fileInputWordMap) {
                char key = subPair.first;
                int count = subPair.second;
                if (InputWordMap[key] < fileInputWordMap[key]) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                result.push_back(fileInput);
            }
        }
    }
    fs.close();
    answer = result;
}

void Form::PrintFoundWords() {
    for (string item : answer) {
        cout << item << endl;
    }
}