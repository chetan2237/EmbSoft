#include "Activity2.h"



int main(void)
{
    InitADC();
    uint16_t temp;
    while(1)
    {
        temp=ReadADC(0);
        _delay_ms(200);
    }
    return 0;
}