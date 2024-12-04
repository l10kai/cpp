#include <iostream>

using namespace std;

string str;
int last[26];//用于存放同一个字符的最后一个位置 
int pre[100005];//用于求取每个字符的相同字符的上一个位置 
int net[100005];//用于求取每个字符的相同字符的下一个位置 
//复杂度为 n 
int main()
{
	cin>>str;//输入一个字符串 
	int ans = 0;//存放结果 
	int n = str.size();//计算字符串的长度 
	
	//for(int i=0;i<26;i++) last[i] = -1;//全都初始化为-1 
	//这个for循环是从前往后 
	for(int i = 0;i<n;i++)
	{   
		int x = str[i] - 'a';//x的值对应某个字符（某个小写字母） 
		pre[i] = last[x];
		last[x] = i;
        //首先假设 x 所对应的字符是 e ,那么last[x]表示字符e最后出现的位置（位置为i），且一直在更新。
		//所以下次循环中 pre[i]存放的是 本次循环 的e的位置，所以 pre[i]存放的就是最新的e的位置的上一个位置。 
		//所以以此类推，pre[]存放的就是每个字符某个位置的上一个位置 
	}
	
	//for(int i=0;i<26;i++) last[i] = n;
	//这个循环是从后向前 
	for(int i=n-1;i>=0;i--)
	{
		int x = str[i] - 'a';
		net[i] = last[x];
		last[x] = i;
        //此处的解释参考上面pre[] 
	}
	//这个循环就是求结果 
	for(int i =0;i<n;i++)
	{
		// (i - pre[i]) * (next[i] - i)是一个排列组合问题， 
		ans += (long long)(i - pre[i]) * (net[i] - i);
	}
	cout<<ans<<endl;
	return 0;
}
