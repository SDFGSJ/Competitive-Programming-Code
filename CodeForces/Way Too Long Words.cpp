#include<stdio.h>
#include<string.h>
char str[105];
int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		int len=strlen(str);
		if(len>10){
			printf("%c%d%c\n",str[0],len-2,str[len-1]);
		}else{
			printf("%s\n",str);
		}
	}
	return 0;
}
