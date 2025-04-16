#include "HotDogStand.h"

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand() {
    standId = new char[1];
    standId[0] = '\0';
    hotDogSellAmount = 0;
    totalSellAmount += hotDogSellAmount;
}

HotDogStand::HotDogStand(const char* id) {
    standId = new char[strlen(id) + 1];
    strcpy_s(standId, strlen(id) + 1, id);
    hotDogSellAmount = 0;
    totalSellAmount += hotDogSellAmount;
}

HotDogStand::HotDogStand(const char* id, int amount) {
    standId = new char[strlen(id) + 1];
    strcpy_s(standId, strlen(id) + 1, id);
    hotDogSellAmount = amount;
    totalSellAmount += hotDogSellAmount;
}

HotDogStand::~HotDogStand() {
    standId = new char[1];
    standId[0] = '\0';
    hotDogSellAmount = 0;
    totalSellAmount += hotDogSellAmount;
}

void HotDogStand::justSold() {
    hotDogSellAmount++;
    totalSellAmount++;
}

void HotDogStand::print() {
    std::cout << standId << " " << hotDogSellAmount << std::endl;
}

int HotDogStand::thisStandSoldAmount() {
    return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount() {
    return totalSellAmount;
}
