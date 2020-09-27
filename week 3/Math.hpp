#pragma once

constexpr double Fac(int x)
{
    double res = 1;
    while(x > 1)
    {
        res *= x;
        x--;
    }
    return res;
}

constexpr double Pow(double x, int y)
{
    double res = 1;
    while(y > 0)
    {
        res *= x;
        y--;
    }
    return res;
}

constexpr double ToRadian(int alpha)
{
    return 2 * 3.14 * (alpha / 360.0);
}

constexpr double Sin(double x)
{
    return x - (Pow(x, 3) / Fac(3)) + (Pow(x, 5) / Fac(5)) - (Pow(x, 7) / Fac(7)) + (Pow(x, 9) / Fac(9)) - (Pow(x, 11) / Fac(11)) + (Pow(x, 13) / Fac(13));
}

constexpr double Cos(double x)
{
    return Sin(1.57 - x);
}