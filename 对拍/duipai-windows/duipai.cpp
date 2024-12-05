#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long times = 1;
    while (1) //һֱѭ����ֱ���ҵ���һ��������
    {
        system("data.exe");
        system("std.exe");
        system("my_code.exe");
        printf("%lld",times ++);
        if (system("fc my_code.txt baoli.txt")) //�� fc ���� 1 ʱ��˵����ʱ���ݲ�һ��
            break;                          //��һ��������ѭ��
    }
    return 0;
}

