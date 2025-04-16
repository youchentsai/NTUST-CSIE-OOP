#include "Month.h"
#include <iostream>

std::map<std::string, int> MONTH_TABLE = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},  {"May", 5},  {"Jun", 6},
                                          {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};

Month::Month() {
    month = 1;
}

Month::Month(char first, char second, char third) {
    // strcat 3 char into 1 string
    std::string monthStr = "";
    monthStr.insert(monthStr.end(), first);
    monthStr.insert(monthStr.end(), second);
    monthStr.insert(monthStr.end(), third);
    month = (MONTH_TABLE[monthStr] == 0) ? 1 : MONTH_TABLE[monthStr];
}

Month::Month(int monthInt) {
    month = (monthInt <= 12 && monthInt >= 1) ? monthInt : 1;
}

Month::~Month() {}

void Month::inputInt() {
    int mon;
    std::cin >> mon;
    month = (mon <= 12 && mon >= 1) ? mon : 1;
}

void Month::inputStr() {
    char first, second, third;
    std::cin >> first >> second >> third;
    // strcat 3 char into 1 string
    std::string monthStr = "";
    monthStr.insert(monthStr.end(), first);
    monthStr.insert(monthStr.end(), second);
    monthStr.insert(monthStr.end(), third);
    month = (MONTH_TABLE[monthStr] == 0) ? 1 : MONTH_TABLE[monthStr];
}

void Month::outputInt() {
    std::cout << month;
}

void Month::outputStr() {
    for (std::pair<std::string, int> item : MONTH_TABLE) {
        if (item.second == month) {
            std::cout << item.first;
        }
    }
}

Month Month::nextMonth() {
    return Month{(month % 12) + 1};
}
