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
        //in de while loop moet iets dat de tijd controleerd
        while(true)
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

        minuteTime += 1;
        if(((minuteTime + 12) % 12) == 0)
        {
            hourTime += 1;
        }
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