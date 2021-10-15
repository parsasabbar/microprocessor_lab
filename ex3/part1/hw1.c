#include <delay.h>
#include <io.h>

int SS[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };

void main(void)
{
int i;
DDRA = 0xff;
while (1)
    {
    for(i = 0; i < 10; i++){
        PORTA = SS[i];
        delay_ms(1000);
    }
    }
}
