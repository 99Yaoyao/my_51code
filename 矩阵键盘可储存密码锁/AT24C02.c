#include "I2C.h"
#include "AT24C02.h"
#include <REGX52.H>

void AT24C02_writeByte(unsigned char addr, unsigned char byte) // 对从机某个地址写入一个数据
{
    I2C_start();        // 开始
    I2C_sendByte(0xA0); // 往I2C总线上发送地址寻找对应从机
    I2C_receiveAck();   // 从机应答
    I2C_sendByte(addr); // 发送要写入数据的地址，称为字地址，就是数据存在哪
    I2C_receiveAck();   // 从机应答
    I2C_sendByte(byte); // 要在字地址上写入什么数据
    I2C_receiveAck();   // 从机应答
    I2C_stop();         // 停止
}

unsigned char AT24C02_readByte(unsigned char addr) // 对从机某个地址读出一个数据,写加读（复合格式）
{
    unsigned char dat = 0; // 定义一个变量接收读出的数据
    I2C_start();           // 开始
    I2C_sendByte(0xA0);    // 发送从机地址+写操作（0为写1为读）等待从机应答
    I2C_receiveAck();      // 从机应答
    I2C_sendByte(addr);    // 发送要读的数据所在地址
    I2C_receiveAck();      // 从机应答

    I2C_start();             // 再来一个开始
    I2C_sendByte(0xA1);      // 发送从机地址+读操作等待从机应答
    I2C_receiveAck();        // 从机应答
    dat = I2C_receiveByte(); // 从机读出数据所在地址包含的数据并发送出来
    I2C_sendAck(1);          // 主机不应答
    I2C_stop();              // 停止
    return dat;
}

//#include "I2C.h"
//#include <REGX52.H>
///*
//void AT24C02_writeByte(unsigned char addr,unsigned char dat)//对从机某个地址写入一个数据
//{
//    I2C_start();//开始
//    I2C_send_byte(0xA0);//往I2C总线上发送地址寻找对应从机
//    I2C_receive_ack();//从机应答
//    I2C_send_byte(addr);//发送要写入数据的地址，称为字地址，就是数据存在哪
//    I2C_receive_ack();//从机应答
//    I2C_send_byte(dat);//要在字地址上写入什么数据
//    I2C_receive_ack();//从机应答
//    I2C_stop();//停止
//}
//unsigned char AT24C02_readByte(unsigned char addr)//对从机某个地址读出一个数据,写加读（复合格式）
//{
//    unsigned char dat = 0;//定义一个变量接收读出的数据
//    I2C_start();//开始
//    I2C_send_byte(0xA0);//发送从机地址+写操作（0为写1为读）等待从机应答
//    I2C_receive_ack();//从机应答
//    I2C_send_byte(addr);//发送要读的数据所在地址
//    I2C_receive_ack();//从机应答
//    
//    I2C_start();//再来一个开始
//    I2C_send_byte(0xA1);//发送从机地址+读操作等待从机应答
//    I2C_receive_ack();//从机应答
//    dat = I2C_receive_byte();//从机读出数据所在地址包含的数据并发送出来
//    I2C_send_ack(1);//主机不应答
//    I2C_stop();//停止
//    return dat;
//}







