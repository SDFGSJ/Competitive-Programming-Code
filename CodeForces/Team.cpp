#include<stdio.h>
int a[4];
int main(void)
{
	int i,j;
	int n,count=0,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[j]);
			if(a[j]==1){
				count++;
			}
		}
		if(count>=2){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
