#include<stdio.h>
int num[105];
int main(void)
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		int len,even=0,even_idx=-1;
		scanf("%d",&len);
		for(i=0;i<len;i++){
			scanf("%d",&num[i]);
			if(num[i]%2==0){
				even=1;
				even_idx=i;
			}
		}
		if(even){
			printf("1\n%d\n",even_idx+1);
			continue;
		}
		if(len>1){
			printf("2\n1 2\n");
		}else{
			printf("-1\n");
		}
	}
	return 0;
}
