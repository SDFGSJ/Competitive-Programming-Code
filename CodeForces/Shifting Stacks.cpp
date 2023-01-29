#include<stdio.h>
long long h[105];
int main(void)
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n,yes=1;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lld",&h[i]);
		}
		for(i=0;i<n-1;i++){
			if(h[i]>=i){
				h[i+1]+=(h[i]-i);
				h[i]=i;
			}else{
				yes=0;
				break;
			}
		}
		for(i=0;i<n;i++){
			if(h[i]<i){
				yes=0;
				break;
			}
		}
		if(yes)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
