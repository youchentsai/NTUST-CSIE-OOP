#pragma once
#include <cstring>
#include <iostream>
class HotDogStand {
public:
    HotDogStand();
    HotDogStand(const char* id);
    HotDogStand(const char* id, int amount);
    ~HotDogStand();
    void justSold();
    void print();
    int thisStandSoldAmount();
    static int allStandSoldAmount();

private:
    char* standId;
    int hotDogSellAmount;
    static int totalSellAmount;
};
