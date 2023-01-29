#include<stdio.h>
int num[100010];
int query[100010];
int n;
int main(void)
{
	int i,j;
	int q,zero=0,one=0;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]==0){
			zero++;
		}else{
			one++;
		}
	}
	for(i=0;i<q;i++){
		int k;
		scanf("%d%d",&query[i],&k);
		if(query[i]==1){
			if(num[k-1]==0){
				zero--;
				one++;
			}else{
				zero++;
				one--;
			}
			num[k-1]=1-num[k-1];
		}else{
			if(k>one){
				printf("0\n");
			}else{
				printf("1\n");
			}
		}
	}
	return 0;
}
