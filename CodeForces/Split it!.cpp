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
		
		//�p�Gk�O0�A����print yes
		if(k==0){
			printf("YES\n");
			continue;
		}
		
		/*
		�ˬd�r�Ƹ�k���������Y(strlen>=2*k+1)�A�p�G���ŦX����print no
		���ŦX�~�ˬd�O���Opalindrome
		*/
		if(len<2*k+1){
			printf("NO\n");
			continue;
		}else{
			for(i=0;i<len;i++){
				if(str[i]!=str[len-1-i] && i+1<=k){	//exception:abcmopponcba�Babcmopqomcba
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
