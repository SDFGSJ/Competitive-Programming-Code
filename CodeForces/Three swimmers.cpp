#include<stdio.h>
int main(void)
{
	int t,i;
	long long a[3];
	scanf("%d",&t);
	while(t--){
		long long m,num=0,min=1e18;
		scanf("%lld%lld%lld%lld",&m,&a[0],&a[1],&a[2]);
		for(i=0;i<3;i++){
			if(m<=a[i]){
				num=a[i]-m;
			}else{
				if(m%a[i]==0){	//如果可以整除的話min就一定是0了，不用繼續跑迴圈 
					min=0;
					break;
				}else{
					num=a[i]-m%a[i];
				}
			}
			if(num<min)	min=num;
		}
		printf("%lld\n",min);
	}
	return 0;
}
