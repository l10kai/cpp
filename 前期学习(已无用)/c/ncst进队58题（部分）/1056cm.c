#include<stdio.h>

typedef struct{
	int x;
	int num;
}st;

st a[100000];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n+m;i++){
		scanf("%d %d",&a[i].x,&a[i].num);
	}	
	
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m-i;j++){
			if(a[j].x>a[j+1].x){
				st t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
	for(int i=1;i<=n+m;i++){
		printf("%d %d\n",a[i].x,a[i].num);
	}
	
	return 0;	

}