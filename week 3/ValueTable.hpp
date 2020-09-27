#pragma once
#include "hwlib.hpp"
#include "Math.hpp"

class ValueTable
{
private:
    std::array<hwlib::xy, 60> table;
public:

    constexpr ValueTable(hwlib::xy m, int r) : table{}
    {
        for(unsigned int x = 0; x < 60; x++)
        {
            table[x] = hwlib::xy(m.x + (Cos(ToRadian(x * 6 - 90)) * r), m.y + (Sin(ToRadian(x * 6 - 90)) * r));
        }
    }

    hwlib::xy GetValue(unsigned int x)
    {
        return table[x];
    }
};