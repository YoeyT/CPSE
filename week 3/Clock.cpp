#include "Clock.hpp"

Clock::Clock(hwlib::xy middle, hwlib::window& w, hwlib::pin_in& minuteButton, hwlib::pin_in& hourButton) :
    middle(middle),
    outerRing(middle, 26),
    innerRing(middle, 20),
    outerIndicatorRing(middle, 30),
    w(w),
    minuteTime(0),
    hourTime(0),
    minuteButton(minuteButton),
    hourButton(hourButton)
{}

void Clock::Start()
{
    while(true)
    {
        while(!((hwlib::now_us() % 60'000'000) > 0 && (hwlib::now_us() % 60'000'000) < 300'000))
        {
            Draw();

            if(!minuteButton.read())
            {
                if(minuteTime == 59)
                {
                    minuteTime = 0;
                    hourTime += 1;
                }
                else
                {
                    minuteTime += 1;
                    if(((minuteTime + 12) % 12) == 0)
                    {
                        hourTime += 1;
                    }
                }
            }
            else if(!hourButton.read())
            {
                if(hourTime == 55)
                {
                    hourTime = 0;
                }
                else
                {
                    hourTime += 5;
                }
            }
        }

        if(minuteTime == 59)
        {
            minuteTime = 0;
            hourTime += 1;
        }
        else
        {
            minuteTime += 1;
            if(((minuteTime + 12) % 12) == 0)
            {
                hourTime += 1;
            }
        }
        //give cooldown
        hwlib::wait_ms(300);
    }
}

void Clock::Draw()
{
    hwlib::line minutePointer(middle, outerRing.GetValue(minuteTime));
    hwlib::line hourPointer(middle, innerRing.GetValue(hourTime));

    w.clear();
    minutePointer.draw(w);
    hourPointer.draw(w);

    for(unsigned int x = 0; x < 12; x++)
    {
        indicatorArray[x].draw(w);
    }

    w.flush();
}