#include <stdio.h>
int main()
{
    int i, j, n, k, t; 
	long Buf[21]={0,1};    //用于保存一行数据
	printf("请输入杨辉三角形的行数（1 ~ 20）：");
	scanf("%d",&n);
    for( i = 1; i <= n; i++)	//输出n行
    {
		// for( j = 0; j < n - i; j++)	//每行前面补空格，形成等腰三角图案	
		// 	printf("   ");
		t = 0;
        for( j = 1; j <= i; j++)//计算并输出杨辉三角形
        {
			k = Buf[j];
			Buf[j] = t + k;		//每个数是上面两数之和（三角计算）
			t = k;
            printf("%d ", Buf[j]);	
        }
        printf("\n");
    }
	return 0;
}
