#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main() {
    using namespace std;
    set<string> inviteList;
    ifstream fs;
    string fileInput;
    fs.open("name.txt");
    while (getline(fs, fileInput)) {
        inviteList.insert(fileInput);
    }
    fs.close();
    for (set<string>::iterator it = inviteList.begin(); it != inviteList.end(); ++it) {
        cout << it->c_str() << endl;
    }
    return 0;
}