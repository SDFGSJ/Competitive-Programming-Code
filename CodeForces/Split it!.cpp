#include<stdio.h>
char str[105];
int main(void)
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		int len,k,no=0;
		scanf("%d%d",&len,&k);
		scanf("%s",str);
		
		//如果k是0，直接print yes
		if(k==0){
			printf("YES\n");
			continue;
		}
		
		/*
		檢查字數跟k之間的關係(strlen>=2*k+1)，如果不符合直接print no
		有符合才檢查是不是palindrome
		*/
		if(len<2*k+1){
			printf("NO\n");
			continue;
		}else{
			for(i=0;i<len;i++){
				if(str[i]!=str[len-1-i] && i+1<=k){	//exception:abcmopponcba、abcmopqomcba
					no=1;
					break;
				}
			}
		}
		if(!no){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
