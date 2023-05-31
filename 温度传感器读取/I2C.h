//#include <REGX52.H>

#ifndef __I2C_H__
#define __I2C_H__

void I2C_start();
void I2C_send_byte(unsigned char dat);
void I2C_stop();
void I2C_send_ack(unsigned char ack);
unsigned char I2C_receive_byte();
unsigned char I2C_receive_ack();

#endif