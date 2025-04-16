#include <map>
#include <string>
#include <vector>
#include "Diary.h"

class Creature {
public:
    std::string name;
    std::map<std::string, double> bodyPart;
    std::map<std::string, std::vector<std::string>> logs;
    int startIndex = 0;

    Creature(std::string n) {
        name = n;
        startIndex = Diary::dayIndex;
    }

    Creature(std::string n, const Creature& c)
        : name(n)
        , bodyPart(c.bodyPart)
        , startIndex(Diary::dayIndex){}

    //double& operator[](std::string& part);

    class Proxy {
    private:
        Creature& creature;
        std::string part;

    public:
        Proxy(Creature& c, const std::string& _part)
            : creature(c)
            , part(_part){};

        Proxy& operator=(double value);
        Proxy& operator+=(double value);
        Proxy& operator-=(double value);

        operator double() const {
            return creature.bodyPart[part];
        }
    };

    Proxy operator[](const std::string& part);

    void PrintStatus();

    void PrintLog();
};
