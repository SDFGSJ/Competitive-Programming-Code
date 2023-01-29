#include<stdio.h>
int num[105];
int main(void)
{
	int i,j,k;
	int n,max=-1,global_1=0,local_1,local_0,now=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]==1)	global_1++;
	}
	if(global_1==n){
		max=n-1;
	}else{
		for(i=0;i<n;i++){
			for(j=i;j<n;j++){	//j從i開始會比從0開始快2倍 
				now=local_0=local_1=0;
				for(k=i;k<=j;k++){
					if(num[k]==1){
						local_1++;
					}else{
						local_0++;
					}
				}
				now=global_1-local_1+local_0;
				if(now>max)	max=now;
				//printf("[%d,%d] ==> 0的個數=%d , 1的個數=%d,now=%d - %d + %d = %d,目前max=%d\n",i,j,local_0,local_1,global_1,local_1,local_0,now,max);
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
