#include "hwlib.hpp"
extern "C" void uart_put_char(char c);
extern "C" void _start();

void uart_put_char( char c ){
   hwlib::cout << c;
}

int main(void)
{
   hwlib::wait_ms(2000);
   _start();
}