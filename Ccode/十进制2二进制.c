#include <stdio.h>
int G_yu[100] = {0}, G_cnt = 0;
int main()
{
    char str[] = "123456789012345678901234567890";
    //char str[] = "255";
    bignum2two(str);
    G_cnt--;
    while (G_cnt != -1)
    {
        printf("%d-", G_yu[G_cnt]);
        G_cnt--;
    }
    printf("\nEND");
    getchar();
    return 0;
}

int ten2two(int num)
{
    int yushu = 0;
    int msb = 1;
    int result = 0;
    while (1)
    {
        if (num >= 2)
        {
            yushu = num % 2;
            num = num / 2;         //产生新的num
            result += msb * yushu; //0不会产生影响，因为msb在倍乘
            msb *= 10;
            printf("----:%d\n", result);
        }

        if (num < 2)
        {
            result += msb * num;
            printf("----:%d\n", result);
            break;
        }
    }
    return result;
}

void bignum2two(char str[])
{

    // 比如40位的字符串，没办法先将其转化整数
    int num[31];
    int yushu = 0;
    int i = 0, j = 0, index;
    while (str[j] != '\0')
    {

        num[j] = str[j] - '0';
        j++;
    }

    //代码表达除法运算，如xxxx / 2, 目标是得到最后的余数
    for (index = 0; index < 30;)
    {

        //计算被除数开始的位置，如00032，开始做除法的位置是3

        for (i = index; i < 30; i++)
        {

            yushu = num[i] % 2;
            if (yushu == 0)
            {
                num[i] = num[i] / 2;
            }
            else
            {
                num[i] = num[i] / 2;
                num[i + 1] += 10 * yushu;
            }
        }
        printf("yushu:%d\n", yushu);
        G_yu[G_cnt] = yushu; // 将该次计算的最终余数保存在num[i]中;
        G_cnt++;

        while (num[index] == 0)
            index++;
    }
}