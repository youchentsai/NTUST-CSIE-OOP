#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool readQuotedString(istringstream& iss, string& result) {
    result.clear();
    iss >> ws;
    if (iss.peek() != '"')
        return false;
    iss.get(); // remove leading "

    char ch;
    while (iss.get(ch)) {
        if (ch == '"')
            break;
        result += ch;
    }

    return true;
}

int main() {
    map<pair<string, string>, set<int>> database;
    string line;

    while (getline(cin, line)) {
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "Insert") {
            string title, author;
            int edition;
            if (readQuotedString(iss, title) && readQuotedString(iss, author) && iss >> edition) {
                auto key = make_pair(title, author);
                if (database[key].count(edition)) {
                    cout << "Datum already exist." << endl;
                } else {
                    database[key].insert(edition);
                    cout << "Insert " << author << "'s " << title << ", Edition: " << edition << "." << endl;
                }
            } else {
                cout << "Incomplete Command." << endl;
            }
        } else if (command == "Delete") {
            string type;
            if (!(iss >> type)) {
                cout << "Incomplete Command." << endl;
                continue;
            }

            if (type == "Edition") {
                string title, author;
                int edition;
                if (readQuotedString(iss, title) && readQuotedString(iss, author) && iss >> edition) {
                    auto key = make_pair(title, author);
                    if (database.count(key) && database[key].count(edition)) {
                        database[key].erase(edition);
                        cout << "Delete " << author << "'s " << title << ", Edition: " << edition << "." << endl;
                        if (database[key].empty()) {
                            database.erase(key);
                        }
                    } else {
                        cout << "Datum doesn't exist." << endl;
                    }
                } else {
                    cout << "Incomplete Command." << endl;
                }
            } else if (type == "Book") {
                string title, author;
                if (readQuotedString(iss, title) && readQuotedString(iss, author)) {
                    auto key = make_pair(title, author);
                    if (database.count(key)) {
                        for (int ed : database[key]) {
                            if (database[key].size() != 1)
                                cout << "Delete " << author << "'s " << title << ", Edition: " << ed << "." << endl;
                            else {
                                cout << "Delete " << author << "'s " << title << "." << endl;
                            }
                        }
                        database.erase(key);
                    } else {
                        cout << "Book doesn't exist." << endl;
                    }
                } else {
                    cout << "Incomplete Command." << endl;
                }
            }
        } else if (command == "Find") {
            string type;
            if (!(iss >> type)) {
                cout << "Incomplete Command." << endl;
                continue;
            }

            if (type == "Book") {
                string title, author;
                if (readQuotedString(iss, title) && readQuotedString(iss, author)) {
                    auto key = make_pair(title, author);
                    if (database.count(key)) {
                        cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: ";
                        bool first = true;
                        for (int ed : database[key]) {
                            if (!first)
                                cout << ", ";
                            cout << ed;
                            first = false;
                        }
                        cout << endl;
                    } else {
                        cout << "Book doesn't exist." << endl;
                    }
                } else {
                    cout << "Incomplete Command." << endl;
                }
            } else if (type == "Author") {
                string author;
                if (readQuotedString(iss, author)) {
                    set<string> titles;
                    for (pair<pair<string, string>, set<int>> p : database) {
                        pair<string, string> key = p.first;
                        set<int> edition = p.second;
                        if (key.second == author) {
                            titles.insert(key.first);
                        }
                    }
                    if (titles.empty()) {
                        cout << "No book found." << endl;
                    } else {
                        cout << author << "'s Books: ";
                        bool first = true;
                        for (auto& t : titles) {
                            if (!first)
                                cout << ", ";
                            cout << t;
                            first = false;
                        }
                        cout << endl;
                    }
                } else {
                    cout << "Incomplete Command." << endl;
                }
            }
        } else if (command == "Sort") {
            string by, next;
            if (!(iss >> by)) {
                cout << "Incomplete Command." << endl;
                continue;
            }

            if (by == "by") {
                iss >> next;
                by += " " + next;
            }

            vector<tuple<string, string, set<int>>> records;
            for (pair<pair<string, string>, set<int>> p : database) {
                pair<string, string> key = p.first;
                set<int> editions = p.second;
                records.emplace_back(key.first, key.second, editions);
            }

            if (by == "by Title") {
                sort(records.begin(), records.end(), [](auto& a, auto& b) {
                    return get<0>(a) == get<0>(b) ? get<1>(a) < get<1>(b) : get<0>(a) < get<0>(b);
                });
            } else if (by == "by Author") {
                sort(records.begin(), records.end(), [](auto& a, auto& b) {
                    return get<1>(a) == get<1>(b) ? get<0>(a) < get<0>(b) : get<1>(a) < get<1>(b);
                });
            } else {
                cout << "Unknown Command." << endl;
                continue;
            }

            for (tuple<string, string, set<int>> data : records) {
                cout << "Title: " << get<0>(data) << "\tAuthor: " << get<1>(data) << "\tEdition: ";
                bool first = true;
                for (int ed : get<2>(data)) {
                    if (!first)
                        cout << ", ";
                    cout << ed;
                    first = false;
                }
                cout << endl;
            }
        } else {
            cout << "Unknown Command." << endl;
        }
    }

    return 0;
}
