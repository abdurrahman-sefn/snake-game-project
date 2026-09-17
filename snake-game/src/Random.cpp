#include <climits>

#include "utils/Random.hpp"


Random::Random() : _generator(_randSeed()), _distribution(0, INT_MAX - 1) {}

int Random::Next()
{
    return _distribution(_generator);
}

int Random::Next(int min, int max)
{
    int len = max - min + 1;

    if (len == 1)
        return min;

    int random = Next() % len;
    return random + min;
}