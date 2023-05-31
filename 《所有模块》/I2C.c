#include <REGX52.H>

sbit SCL = P2^1;
sbit SDA = P2^0;

void I2C_start()//发送开始
{
    SCL = 1;
    SDA = 1;
    SDA = 0;
    SCL = 0;
}

void I2C_stop()//发送停止
{
    SDA = 0;
    SCL = 1;
    SDA = 1;  
}

void I2C_send_byte(u8 dat)//发送一个字节
{
    u8 i = 0;
    for(i = 0; i<8; i++)
    {
        SDA = dat & (0x80>>i);
        SCL = 1;
        SCL = 0;
    }
}

u8 I2C_receive_byte()//接收一个字节
{
    u8 da = 0;
    u8 i = 0;
    SDA = 1;
    for(i = 0; i < 8; i++)
    {
        SCL = 1;
        if(SDA)
            da |= (0x80>>i);//从机如果拉低，就是0，dat的i位不变还是0，
                             //从机如果松开，就是1，dat的i位，置1，
                             //如此循环八次把dat的值变成从机发送的数据            
        SCL = 0;
    }
    return da;
}

void I2C_send_ack(unsigned char ack)//bit是51中特有的数据位，sizeof（bit）= 1bit
{                                   //发送应答
    SDA = ack & 0x01;
    SCL = 1;
    SCL = 0;
}

u8 I2C_receive_ack()//接收应答,0为应答1为不应答
{
    u8 ack = 0;
    SDA = 1;
    SCL = 1;
    if(SDA)
        ack = 1;//此时SDA控制权已经交给从机，
                //从机不拉则返回1，拉低则表示应答返回0
    SCL = 0;
    return ack;
}




