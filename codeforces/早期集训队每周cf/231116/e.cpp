#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
 
ll cal(ll x)
{
	return x*(3*x+1)/2;
}
 
int main()
{
	ll n;
	while(scanf("%lld",&n)!=EOF)
	{
		ll ans=0;
		for(ll i=1;cal(i)<=n;i++)//关键在于楼层数 
		{
			if((n-cal(i))%3==0)	ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}