#include <cmath>
#include <string>
using namespace std;

class Atoi {

private:
    string beTrans;

public:
    Atoi();
    Atoi(string s);
    void SetString(string s);
    const string GetString();
    int Length();
    bool IsDigital();
    int StringToInteger();
};

Atoi::Atoi() {
    beTrans = "";
}

Atoi::Atoi(string s) {
    beTrans = s;
}

void Atoi::SetString(string s) {
    beTrans = s;
}

const string Atoi::GetString() {
    return beTrans;
}

int Atoi::Length() {

    return beTrans.length() - (beTrans[0] == '-' ? 1 : 0);
}

bool Atoi::IsDigital() {
    bool isValid = true;
    for (int i = 0; i < beTrans.length(); i++) {
        if (beTrans[0] == '-' && beTrans.length() != 1)
            continue;
        if (beTrans[i] > '9' || beTrans[i] < '0')
            isValid = false;
    }
    return isValid;
}

int Atoi::StringToInteger() {
    bool isNegetive = beTrans[0] == '-' ? true : false;
    bool isFrontZero = true;
    string tempStr = beTrans;
    int result = 0;
    for (int i = isNegetive ? 1 : 0; i < tempStr.length(); i++) {
        if (tempStr[i] != '0') {
            isFrontZero = false;
            result += (tempStr[i] - '0') * pow(10, tempStr.length() - i - 1);
        }
        if (isFrontZero) {
            tempStr.erase(tempStr.begin() + i);
            i--;
            continue;
        }
        beTrans = tempStr;
    }
    return result * (isNegetive ? -1 : 1);
}