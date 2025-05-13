#pragma once
#ifndef SCHOOL_H
#    define SCHOOL_H
#    include <cmath>
#    include <iostream>
#    include <string>

class School {
public:
    std::string name;
    int studentAmount;
    int studentAmountNextYear;

    School(std::string _name, int _studentAmount)
        : name(_name)
        , studentAmount(_studentAmount)
        , studentAmountNextYear(_studentAmount){};

    virtual ~School() = default;

    void admissions(float amount) {
        if (amount >= 0)
            studentAmount += amount;
    }

    virtual void dropouts(float amount) {
        if (amount >= 0 && amount <= studentAmount)
            studentAmount -= amount;
    }

    void transfer(float amount, School& toSchool) {
        if (amount <= studentAmount) {
            dropouts(amount);
            toSchool.admissions(amount);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, School& s) {
        os << s.name << "\t" << s.studentAmount << "\t" << s.studentAmountNextYear;
        return os;
    }
};

class PrivateSchool : public School {
public:
    int dropoutCount = 0;
    PrivateSchool(std::string _name, int _studentAmount)
        : School(_name, _studentAmount)
        , dropoutCount(0){};

    void dropouts(float amount) override {
        if (amount >= 0 && amount <= studentAmount)
            studentAmount -= amount;
        if (dropoutCount > 0) {
            studentAmountNextYear -= 100;
            if (studentAmountNextYear < 0)
                studentAmountNextYear = 0;
        }
        dropoutCount++;
    }
};

class PublicSchool : public School {
public:
    float growing_rate = 0.05;

    PublicSchool(std::string _name, int _studentAmount)
        : School(_name, _studentAmount){};

    void apply_growth() {
        studentAmountNextYear += studentAmountNextYear * growing_rate;
    }

    void dropouts(float amount) override {
        int amt = static_cast<int>(amount);
        if (amt >= 0 && amt <= studentAmount) {
            studentAmount -= amt;
            if (amt > 100) {
                studentAmountNextYear -= studentAmountNextYear * 0.05;
                if (studentAmountNextYear < 0)
                    studentAmountNextYear = 0;
            }
        }
    }
};

#endif // !SCHOOL_H
