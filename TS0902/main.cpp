#include<iostream>
#include<string>
#include"password.h"
#include"user.h"

int main() {
    using namespace std;
    using namespace Authenticate;
    inputUserName();
    inputPassword();

    cout << "Your username is " << getUserName() << " and your password is: " << getPassword() << endl;

    return 0;
}