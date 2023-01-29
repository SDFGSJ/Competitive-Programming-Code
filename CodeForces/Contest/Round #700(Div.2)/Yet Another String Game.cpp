#include<stdio.h>
#include<string.h>
char str[55];
int main(void)
{
	int t,i;
	int len;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		len=strlen(str);
		for(i=0;i<len;i++){
			 if(i%2==0){	//alice
			 	if(str[i]!='a'){
			 		str[i]='a';	
				}else{
					str[i]='b';
				}
			 }else{	//bob
			 	if(str[i]!='z'){
			 		str[i]='z';
				 }else{
				 	str[i]='y';
				 }
			 }
		}
		printf("%s\n",str);
	}
	return 0;
}
