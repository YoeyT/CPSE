#include "hwlib.hpp"
#include "Math.hpp"
#include "Clock.hpp"

int main()
{
    hwlib::target::pin_oc scl(hwlib::target::pins::scl);
    hwlib::target::pin_oc sda(hwlib::target::pins::sda);

    hwlib::target::pin_in button1(2, 24);
    hwlib::target::pin_in button2(2, 23);

    hwlib::i2c_bus_bit_banged_scl_sda i2c_bus( scl,sda );

    hwlib::glcd_oled display( i2c_bus, 0x3c );

    Clock klok(hwlib::xy(63, 31), display, button1, button2);
    klok.Start();
    
    return 0;
}