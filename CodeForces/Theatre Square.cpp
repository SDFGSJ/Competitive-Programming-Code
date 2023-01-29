#include<stdio.h>
int main(void)
{
	long long n,m,a;
	scanf("%lld%lld%lld",&n,&m,&a);
	if(n%a==0){
		n/=a;
	}else{
		n=n/a+1;
	}
	if(m%a==0){
		m/=a;
	}else{
		m=m/a+1;
	}
	//printf("m=%d,n=%d\n",m,n);
	printf("%lld\n",m*n);
	return 0;
}
