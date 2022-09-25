#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <random>
#include <bits/stdc++.h>

class Random
    {
    public:
        Random() {};
        auto operator()(int a, int b)
            {
            std::random_device rd;
            std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd() };
            std::mt19937 eng = std::mt19937(seed);
            std::uniform_int_distribution<int> dist(a, b);
            return dist(eng);
            }
    };

#endif // __RANDOM_H__