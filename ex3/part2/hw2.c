#include <delay.h>
#include <io.h>

int SS[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };

void print(int num){
    int i;
    for(i = 0; i < 50; i++){
        PORTC = 0b11110111;
        PORTA = SS[(num / 1) % 10];
        delay_ms(5);
        PORTC = 0b11111011;
        PORTA = SS[(num / 10) % 10];
        delay_ms(5);
        PORTC = 0b11111101;
        PORTA = SS[(num / 100) % 10];
        delay_ms(5);
        PORTC = 0b11111110;
        PORTA = SS[(num / 1000) % 10];
        delay_ms(5);    
    }
}

void main(void)
{
    int temp;
    DDRA = 255;
    DDRC = 255;
    while (1){
        for(temp = 0; temp < 1000; temp++){
            print(temp);
        }
    }
}
