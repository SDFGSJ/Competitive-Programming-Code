#include<stdio.h>
int num[55];
int main(void)
{
	int i;
	int n,m,count=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<n;i++){
		if(num[i]>=num[m-1] && num[i]!=0){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
