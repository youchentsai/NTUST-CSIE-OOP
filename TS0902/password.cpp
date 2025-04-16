#include <cctype>
#include <iostream>
#include <string>
#include"password.h"

namespace {
std::string password;
bool isValid() {
    if (password.length() >= 8) {
        int noneLettercount = 0;
        for (char i : password) {
            if (isalpha(i))
                continue;
            noneLettercount++;
        }
        if (noneLettercount > 0)
            return true;
    }
    return false;
}
} // namespace

namespace Authenticate {
using namespace std;
void inputPassword() {
    do {
        cout << "Enter your password (at least 8 characters "
             << "and at least one non-letter)" << endl;
        cin >> password;
    } while (!isValid());
}

string getPassword() {
    return password;
}
} // namespace Authenticate
