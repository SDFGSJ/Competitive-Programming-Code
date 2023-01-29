#include<stdio.h>
#include<string.h>
int num[1005];
int main(void)
{
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		memset(num,0,sizeof(num));
		int n,sum;
		scanf("%d%d",&n,&sum);
		int cnt=n;
		num[sum]=-1,cnt--;
		for(i=1,j=sum-1 ; i<j ; i++,j--){
			if(i+j==sum){
				num[i]=-1,cnt--;
			}
		}
		printf("%d\n",cnt);
		for(i=1;i<=n;i++){
			if(num[i]!=-1){
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}
