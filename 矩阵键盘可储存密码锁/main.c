#include "main.h"

unsigned char KeyNum = 0;         // 接收矩阵键盘返回的值
unsigned char keyboard_Count = 0; // 记录键盘输入次数
unsigned char Password_Count = 0; // 记录密码输入次数
unsigned int Password = 0;        // 保存输入的密码
unsigned int Password_decide = 0; // 保存正确密码
unsigned int T0Count;             // 定时器计数器
bit isS15 = 0;                    // 判断S15按键是否被按下过
bit isCorrect = 0;                // 保存确认键是否被按下，按下则置1

/*
** 读出AT24C02的数据，如果没有数据则赋默认密码给Password_decide
*/
void passwordInit()
{
    // 从at24c02读取保存的密码，如果没有保存的密码就赋值1234
    if (AT24C02_readByte(1) != 0xff && AT24C02_readByte(2) != 0xff)
    {
        Password_decide = 0;
        Password_decide |= AT24C02_readByte(1) << 8; // 把高八位左移八位（超出范围后数据不会销毁，只是往更高位移）后按位或上Num
        Password_decide |= AT24C02_readByte(2);      // 不能直接赋值，也要按位或上低八位，如果这句写在前面就不用或
    }
    else
    {
        Password_decide = 1234; // 初始默认密码
    }
}

/*
** 判断是否保存密码
*/
void isSave()
{
    AT24C02_writeByte(1, Password / 256); // password高八位保存在地址1
    Delay(5);
    AT24C02_writeByte(2, Password % 256); // password低八位保存在地址2
    Delay(5);
    if (AT24C02_readByte(1) != 0xff && AT24C02_readByte(2) != 0xff)
    {
        LCD_ShowString(2, 1, "Save success!");
    }
    else
    {
        LCD_ShowString(2, 1, "Save error!");
    }
    Delay(2000);
    Password = 0;
    keyboard_Count = 0;
}

/*
** 清空AT24C02保存的值
*/
void AT24C02Init()
{
    AT24C02_writeByte(1, 0xff);
    Delay(5);
    AT24C02_writeByte(2, 0xff);
    Delay(5);
}

/*
** 输入密码
*/
void inputPassword()
{
    if (keyboard_Count < 4) // 只能输入四位密码
    {
        Password *= 10;          // 密码左移一位
        Password += KeyNum % 10; // 下一位密码输入，10作为0，10模10就是0
        keyboard_Count++;        // 键盘计次增加
    }
}

/*
** 判断密码是否正确
*/
void isPassword()
{
    if (Password == Password_decide) // 判断密码是否正确
    {
        Password = 0;
        keyboard_Count = 0;
        Password_Count = 0;
        isCorrect = 1;

        LCD_ShowString(2, 1, "Password, OK");
        Timer0_Init();
    }
    else
    {
        Password_Count++; // 要是输入错误就计次，超过三次就报警
        Password = 0;     // 如果输入错误，密码与计数器都清零，重新输入
        keyboard_Count = 0;

        LCD_ShowString(2, 1, "Password, NO");
        beep_alarm(1000, 10); // 错一次就响一次蜂鸣器
    }
}

/*
** 删除一位密码
*/
void isDelete()
{
    if (keyboard_Count > 0)
    {
        Password /= 10;   // 密码删除一位
        keyboard_Count--; // 计数减少一次
    }
}

void PasswordModel()
{
    // 正常模式
    if (isCorrect == 0)
    {
        // s13作为确认键
        if (KeyNum == 13)
        {
            isPassword();
        }
        LCD_ShowNumber(1, 10, Password);
    }
    // 修改密码模式
    else if (KeyNum == 15 && isCorrect == 1)
    {
        isS15 = 1;
        TR0 = 0; // 停止定时器计时
        T0Count = 0;
        LCD_ShowString(1, 1, "Alter password:");

        // s16作为确认保存键
        LCD_ShowNumber(2, 1, Password);
        LCD_ShowString(2, 5, "        ");
    }
    else
    {
        if (isCorrect == 0)
        {
            LCD_ShowNumber(1, 10, Password);
            LCD_ShowString(2, 1, "Password, OK");
        }
        if (isS15 == 1)
        {
            LCD_ShowNumber(2, 1, Password);
        }
    }
}

int main(void)
{
    // AT24C02Init();
    LCD1602_Init();
    LCD_ShowString(1, 1, "Password:");
    LCD_ShowString(2, 1, "                ");
    passwordInit();

    for (;;)
    {
        // 接收矩阵键盘返回的值
        KeyNum = MatrixKey();
        // 密码模式
        PasswordModel();
        // 键盘值不能超过10且不能为0
        if (KeyNum != 0 && KeyNum <= 10)
        {
            inputPassword();
        }
        // s14作为删除键
        if (KeyNum == 14)
        {
            isDelete();
        }
        if (KeyNum == 16 && isS15 == 1)
        {
            isS15 = 0;
            isCorrect = 0;
            isSave();
            passwordInit();
            goto Break;
        }
        // 定时器启动后如果超过三秒未有动作则结束程序
        if (T0Count >= 3000)
        {
            TR0 = 0; // 停止定时器计时
            T0Count = 0;
            goto Break;
        }
        // 密码错误三次蜂鸣器警报
        if (Password_Count >= 3)
        {
            beep_alarm(1000, 10);
        }
    }
Break:
    return 0;
}

void Timer0_Routine() interrupt 1
{
    TL0 = 0x66;
    TH0 = 0xFC;
    T0Count++;
}