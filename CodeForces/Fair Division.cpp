#include<stdio.h>
int dp[105][105];
int num[105];
int main(void)
{
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		int n,one=0,two=0,sum=0,ok=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
			sum+=num[i];
			if(num[i]==1)	one++;
			else two++;
		}
		if(sum%2!=0){
			printf("NO\n");
			continue;
		}else{
			for(i=0;i<=one;i++){
				for(j=0;j<=two;j++){
					dp[i][j]=1*i+2*j;
				}
			}
			//printf("dp[][]=\n");
			for(i=0;i<=one;i++){
				for(j=0;j<=two;j++){
					if(dp[i][j]==sum/2){
						ok=1;
						break;
					}
				}
				if(ok)	break;
			}
		}
		
		if(ok)	printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
