#include "Creature.h"
#include "Diary.h"
#include <iostream>
#include <sstream>

std::string Diary::current_day;
std::vector<std::string> Diary::daysName;
int Diary::dayIndex = -1;

/*double Creature::operator[](std::string& part) {
    return bodyPart[part];
}*/

Creature::Proxy& Creature::Proxy::operator=(double value) {
    std::stringstream ss;
    double oldValue = creature.bodyPart[part];
    double newValue = value;
    if (oldValue == newValue) {
        //creature.logs[Diary::current_day].push_back("");
        return *this;
    }
    ss << creature.name << "'s " << part
       << (creature.bodyPart[part] == 0      ? " appeared ("
           : creature.bodyPart[part] > value ? " decreased ("
                                             : " increased (")
       << creature.bodyPart[part] << " -> " << value << ").";
    creature.logs[Diary::current_day].push_back(ss.str());
    creature.bodyPart[part] = value;

    return *this;
}

Creature::Proxy& Creature::Proxy::operator+=(double value) {
    std::stringstream ss;
    double oldValue = creature.bodyPart[part];
    double newValue = creature.bodyPart[part] + value;
    if (oldValue == newValue) {
        //creature.logs[Diary::current_day].push_back("");
        return *this;
    }
    ss << creature.name << "'s " << part
       << (oldValue == 0         ? " appeared ("
           : oldValue > newValue ? " decreased ("
                                 : " increased (")
       << oldValue << " -> " << newValue << ").";
    creature.logs[Diary::current_day].push_back(ss.str());
    creature.bodyPart[part] += value;

    return *this;
}

Creature::Proxy& Creature::Proxy::operator-=(double value) {
    std::stringstream ss;
    double oldValue = creature.bodyPart[part];
    double newValue = creature.bodyPart[part] - value;
    if (oldValue == newValue) {
        //creature.logs[Diary::current_day].push_back("");
        return *this;
    }
    ss << creature.name << "'s " << part
       << (oldValue == 0         ? " appeared ("
           : oldValue > newValue ? " decreased ("
                                 : " increased (")
       << oldValue << " -> " << newValue << ").";
    creature.logs[Diary::current_day].push_back(ss.str());
    creature.bodyPart[part] -= value;

    return *this;
}

Creature::Proxy Creature::operator[](const std::string& part) {
    return Proxy(*this, part);
}

void Creature::PrintLog() {
    using namespace std;

    std::string previousDay;
    cout << name << "'s log:" << endl;
    for (int i = startIndex; i <= Diary::dayIndex; i++) {
        cout << "Day " << Diary::daysName[i] << endl;
        if (previousDay == Diary::daysName[i]) continue;
        previousDay = Diary::daysName[i];
        for (string i : logs[Diary::daysName[i]]) {
            cout << i << endl;
        }
    }
    cout << endl;
}

void Creature::PrintStatus() {
    using namespace std;
    cout << name << "'s status:" << endl;
    for (pair<string, double> part : bodyPart) {
        if (part.second == 0)
            continue;
        cout << part.first << " * " << part.second << endl;
    }
    cout << endl;
}