#pragma once
#include<string>
#include<vector>

class Diary {
public:
    static std::string current_day;
    static std::vector<std::string> daysName;
    static int dayIndex;
    static void NewDay(const std::string& day) {
        //if (current_day == day) return;
        current_day = day;
        daysName.push_back(day);
        dayIndex++;
    }
};