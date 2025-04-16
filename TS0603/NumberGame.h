#pragma once
#ifndef NUMBERGAME_H
#define NUMBERGAME_H
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<unordered_set>
#include<algorithm>

class NumberGame {
public:
    int A;
    std::vector<int> digits;
    std::unordered_set<long long int> validProducts;
    std::string fileName;
    std::vector<int> result;

    void SetInput(int);
    void ProcessInput();
    void SetFileName(std::string);
    void LoadNumberList();
    void PrintAllValid();
    void dfs(int index, long long int product);
    void Reset();
};

#endif // !NUMBERGAME_H
