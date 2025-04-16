#include "NumberGame.h"

void NumberGame::SetInput(int input) {
    A = input;
}

void NumberGame::ProcessInput() {
    digits.clear();
    validProducts.clear();
    int temp = A;
    bool haveOne = false;
    while (temp > 0) {
        int d = temp % 10;
        if (d != 0)
            digits.push_back(d);
        if (d == 1)
            haveOne = true;
        temp /= 10;
    }
    dfs(0, 1);

    //digits.erase(remove(digits.begin(), digits.end(), 0), digits.end());
    if (haveOne) {
        validProducts.insert(1);
    }

}

void NumberGame::SetFileName(std::string _fileName) {
    fileName = _fileName;
}

void NumberGame::LoadNumberList() {
    using namespace std;
    long long int maxNumber = 1;
    ifstream fs;
    fs.open(fileName);
    string fileInput;
    while (getline(fs, fileInput)) {
        int number = stoi(fileInput);

        if (validProducts.count(number)) {
            result.push_back(number);
        }
    }
    fs.close();
    sort(result.begin(), result.end());
}

void NumberGame::PrintAllValid() {
    for (int i : result) {
        std::cout << i << std::endl;
    }
}

void NumberGame::Reset() {
    digits = std::vector<int>();
    result = std::vector<int>();
    A = 0;
    fileName = "";
}



void NumberGame::dfs(int index, long long int products) {
    if (index == digits.size()) {
        if (products <= UINT32_MAX && products != 1) {
            validProducts.insert(products);
        }
        return;
    }

    dfs(index + 1, products * digits[index]);

    dfs(index + 1, products);
}

