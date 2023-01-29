#include<stdio.h>
int main(void)
{
	int t;
	int ok=0;
	long long num;
	scanf("%d",&t);
	while(t--){
		ok=0;
		scanf("%lld",&num);
		if(num%2!=0){
			printf("YES\n");
			continue;
		}else{
			while(num!=1){
				num/=2;
				if(num%2!=0 && num!=1){
					ok=1;
					break;
				}
			}
			if(ok){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
