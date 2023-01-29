#include<stdio.h>
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--){
		int w,h,n;
		scanf("%d%d%d",&w,&h,&n);
		int a=1,b=1;
		while(w%2==0){
			w/=2;
			a*=2;
		}
		while(h%2==0){
			h/=2;
			b*=2;
		}
		//printf("a=%d,b=%d\n",a,b);
		if(a*b>=n){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
