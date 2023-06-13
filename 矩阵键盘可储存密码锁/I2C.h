//#ifndef __I2C_H__
//#define __I2C_H__



//void I2C_start(void);

//void I2C_stop(void);

//void I2C_sendByte(unsigned char Data);

//unsigned char I2C_receiveByte(void);

//void I2C_sendAck(unsigned char ack);

//unsigned char I2C_receiveAck();

//#endif


//#include <REGX52.H>

#ifndef __I2C_H__
#define __I2C_H__

void I2C_start();
void I2C_sendByte(unsigned char Data);
void I2C_stop();
void I2C_sendAck(unsigned char ack);
unsigned char I2C_receiveByte();
unsigned char I2C_receiveAck();

#endif
