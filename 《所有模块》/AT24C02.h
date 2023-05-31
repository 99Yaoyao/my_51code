#ifndef __AT24C02_H__
#define __AT24C02_H__

//u8 AT24C02_write(u8 dat);
void AT24C02_write(u8 addr,u8 dat);
u8 AT24C02_read(u8 addr);

#endif