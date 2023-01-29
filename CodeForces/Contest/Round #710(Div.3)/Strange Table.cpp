#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		long long row,col,num;
		scanf("%lld%lld%lld",&row,&col,&num);
		long long x,y;
		if(num%row==0){
			x=num/row;
			y=row;
		}else{
			x=num/row+1;
			y=num%row;
		}
		//printf("x=%lld,y=%lld\n",x,y);
		printf("%lld\n",col*(y-1)+x);
	}
	return 0;
}
