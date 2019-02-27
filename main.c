#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0x20;  // Set up PB5 as output

    while(1)
    {
        PORTB |=(1<<PIN5);
        _delay_ms(1000);

        PORTB &= ~(1<<PIN5);
        _delay_ms(1000);
    }
    return 0;
}