#include<stdio.h>
int dp[500][500];
int main(void)
{
	int t,i,j;
	int num,yes;
	for(i=0;i<500;i++){
		for(j=0;j<500;j++){
			dp[i][j]=2020*i+2021*j;
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&num);
		if(num<2020){
			printf("NO\n");
			continue;
		}
		for(i=0;i<500;i++){
			for(j=0;j<500;j++){
				if(num==dp[i][j]){
					yes=1;
					break;
				}
			}
			if(yes)	break;
		}
		if(yes)	printf("YES\n");
		else	printf("NO\n");
		yes=0;
	}
	return 0;
}
