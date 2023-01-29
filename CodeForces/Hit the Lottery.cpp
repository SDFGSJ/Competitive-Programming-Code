#include<stdio.h>
int main(void)
{
	int i;
	int n,ans=0;
	int coin[5]={100,20,10,5,1};
	scanf("%d",&n);
	for(i=0;n!=0 && i<5;i++){
		ans+=(n/coin[i]);
		n%=coin[i];
	}
	printf("%d\n",ans);
	return 0;
}
