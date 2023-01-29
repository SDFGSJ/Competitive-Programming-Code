#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str[100005];
int main(void)
{
	int t,i;
	int px,py,len;
	int u,d,l,r;
	scanf("%d",&t);
	while(t--){
		int yes=0;
		u=d=l=r=0;
		scanf("%d%d",&px,&py);
		scanf("%s",str);
		len=strlen(str);
		for(i=0;i<len;i++){
			if(str[i]=='U'){
				u++;
			}else if(str[i]=='D'){
				d++;
			}else if(str[i]=='L'){
				l++;
			}else if(str[i]=='R'){
				r++;
			}
			if(px>=0 && r>=px && py>=0 && u>=py){
				yes=1;
				break;
			}else if(px>=0 && r>=px && py<=0 && d>=abs(py)){
				yes=1;
				break;
			}else if(px<=0 && l>=abs(px) && py>=0 && u>=py){
				yes=1;
				break;
			}else if(px<=0 && l>=abs(px) && py<=0 && d>=abs(py)){
				yes=1;
				break;
			}
		}
		if(yes){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
