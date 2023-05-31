#include <REGX52.H>
#include "wire.h"
#include "Delay.h"

void DS18B20_convertT()
{
    OneWire_Init();
    OneWire_SendByte(0xCC);
    OneWire_SendByte(0x44);
}

float DS18B20_readT()
{
    u8 TL = 0;
    u8 TH = 0;
    int tmp = 0;
    float T = 0;
    OneWire_Init();
    OneWire_SendByte(0xCC);
    OneWire_SendByte(0xBE);
    TL = OneWire_ReceiveByte();
    TH = OneWire_ReceiveByte();
    tmp = (TH<<8) | TL;
    T = tmp/16.0;
    return T;
}








