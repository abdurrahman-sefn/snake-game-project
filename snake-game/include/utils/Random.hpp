#pragma once
#include <random>

class Random
{
private:
    std::random_device _randSeed;
    std::mt19937 _generator;
    std::uniform_int_distribution<int> _distribution;
public:
    Random();
    int Next();
    int Next(int min, int max);
};