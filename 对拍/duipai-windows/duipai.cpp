#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long times = 1;
    while (1) //一直循环，直到找到不一样的数据
    {
        system("data.exe");
        system("baoli.exe");
        system("my_code.exe");
        printf("%lld",times ++);
        if (system("fc my_code.txt baoli.txt")) //当 fc 返回 1 时，说明这时数据不一样
            break;                          //不一样就跳出循环
    }
    return 0;
}

