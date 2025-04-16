#include <iostream>
#include "user.h"

namespace {
std::string username;
bool isValid() {
    if (username.length() == 8) {
        for (char i : username) {
            if (!isalpha(i)) {
                return false;
            }
        }
        return true;
    } 
    return false;
}
} // namespace

namespace Authenticate {
using namespace std;
void inputUserName() {
    do {
        cout << "Enter your username (8 letters only)" << endl;
        cin >> username;
    } while (!isValid());
}

string getUserName() {
    return username;
}
} // namespace Authenticate
