#include <iostream>
#include <string>
#include <vector>

typedef struct {
    std::string firstName;
    std::string lastName;
    std::string phone;
} StRec;

void processCommand(
    std::vector<StRec>& student, const std::string& command, const std::string& firstName, const std::string& lastName, const std::string& phone) {
    using namespace std;

    if (command == "insert") {
        for (StRec st : student) {
            if (st.firstName == firstName && st.lastName == lastName && st.phone == phone || student.size() >= 10) {
                cout << "Insert Error" << endl;
                return;
            }
        }
        StRec st;
        st.firstName = firstName;
        st.lastName = lastName;
        st.phone = phone;
        student.push_back(st);
    } else if (command == "delete") {
        for (int i = 0; i < student.size(); i++) {
            StRec st = student[i];
            if (st.firstName == firstName && st.lastName == lastName && st.phone == phone) {
                student.erase(student.begin() + i); // erase the element
                return;
            }
        }
        cout << "Delete Error" << endl;
    } else if (command == "search") {
        for (int i = 0; i < student.size(); i++) {
            StRec st = student[i];
            if (st.firstName == firstName && st.lastName == lastName && st.phone == phone) {
                cout << i << endl;
                return;
            }
        }
        cout << "Search Error" << endl;
    }
}

int main() {
    using namespace std;
    string command, firstName, lastName, phone;
    vector<StRec> student;
    while (true) {

        // input
        cin >> command;
        if (cin.eof())
            return 0;
        if (command == "print") {
            if (student.empty()) {
                cout << "Print Error" << endl;
                continue;
            }

            for (StRec item : student) {
                cout << item.firstName << " " << item.lastName << " " << item.phone << endl;
            }
            continue;
        }

        if (!(cin >> firstName >> lastName >> phone)) {
            cout << "Input Error" << endl;
        }
        // check input error

        if (command != "insert" && command != "delete" && command != "search") {
            cout << "Input Error" << endl;
            continue;
        }

        if (firstName.length() > 25 || lastName.length() > 30 || phone.length() > 15) {
            cout << "Input Error" << endl;
            continue;
        }

        // check phone is number
        try {
            stod(phone);
        } catch (invalid_argument) {
            cout << "Input Error" << endl;
            continue;
        }
        processCommand(student, command, firstName, lastName, phone);
    }
}