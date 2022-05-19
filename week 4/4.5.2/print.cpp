#include "hwlib.hpp"
extern "C" void uart_put_char(char c);

void uart_put_char( char c ){
   hwlib::wait_ms(1);
   hwlib::cout << c;
}