#pragma once
#include "ValueTable.hpp"
#include <thread>

class Clock
{
private:
    hwlib::xy middle;
    ValueTable outerRing, innerRing, outerIndicatorRing;
    hwlib::window& w;

    int minuteTime;
    int hourTime;



    hwlib::pin_in& minuteButton;
    hwlib::pin_in& hourButton;

    std::array<hwlib::line, 12> indicatorArray = 
    {
        hwlib::line(outerRing.GetValue(0), outerIndicatorRing.GetValue(0)),
        hwlib::line(outerRing.GetValue(5), outerIndicatorRing.GetValue(5)),
        hwlib::line(outerRing.GetValue(10), outerIndicatorRing.GetValue(10)),
        hwlib::line(outerRing.GetValue(15), outerIndicatorRing.GetValue(15)),
        hwlib::line(outerRing.GetValue(20), outerIndicatorRing.GetValue(20)),
        hwlib::line(outerRing.GetValue(25), outerIndicatorRing.GetValue(25)),
        hwlib::line(outerRing.GetValue(30), outerIndicatorRing.GetValue(30)),
        hwlib::line(outerRing.GetValue(35), outerIndicatorRing.GetValue(35)),
        hwlib::line(outerRing.GetValue(40), outerIndicatorRing.GetValue(40)),
        hwlib::line(outerRing.GetValue(45), outerIndicatorRing.GetValue(45)),
        hwlib::line(outerRing.GetValue(50), outerIndicatorRing.GetValue(50)),
        hwlib::line(outerRing.GetValue(55), outerIndicatorRing.GetValue(55))
    };

    void Draw();
public:
    Clock(hwlib::xy middle, hwlib::window& w, hwlib::pin_in& minuteButton, hwlib::pin_in& hourButton);

    void Start();
};