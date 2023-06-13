#ifndef __AT24C02_H__
#define __AT24C02_H__

//u8 AT24C02_write(unsigned char dat);
void AT24C02_writeByte(unsigned char addr,unsigned char dat);
unsigned char AT24C02_readByte(unsigned char addr);

#endif