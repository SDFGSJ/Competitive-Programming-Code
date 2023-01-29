#include<stdio.h>
int num[100010];
int dp[100010];
int main(void)
{
	int i;
	int n,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	dp[0]=1;
	for(i=1;i<n;i++){
		if(num[i]>num[i-1]){
			dp[i]=dp[i-1]+1;
		}else{
			dp[i]=1;
		}
	}
	for(i=0;i<n;i++){
		if(dp[i]>max)	max=dp[i];
	}
	/*printf("dp[]=");
	for(i=0;i<n;i++){
		printf("%d,",dp[i]);
	}
	printf("\n");*/
	printf("%d\n",max);
	return 0;
}
