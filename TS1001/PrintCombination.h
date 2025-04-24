#pragma once
#ifndef PRINTCOMBINATION_H
#    define PRINTCOMBINATION_H
#    include <iostream>
#    include <vector>

std::vector<int> source;
void findCombination(std::vector<int> destination, int index, int choiceCount);
void PrintCombination(int* numberArray, int elementCount, int choiceCount) {
    for (int i = 0; i < elementCount; i++) {
        source.push_back(numberArray[i]);
    }
    findCombination(std::vector<int>(), 0, choiceCount);
}

void findCombination(std::vector<int> destination, int index, int choiceCount) {

    if (destination.size() >= choiceCount) {
        for (int i = 0; i < destination.size(); i++) {
            std::cout << destination[i];
            if (i != destination.size() - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
        return;
    }

    if (index >= source.size())
        return;

    // choose this number
    destination.push_back(source[index]);
    findCombination(destination, index + 1, choiceCount);

    // dont choose
    destination.pop_back();
    findCombination(destination, index + 1, choiceCount);
}

#endif // !PRINTCOMBINATION_Hs