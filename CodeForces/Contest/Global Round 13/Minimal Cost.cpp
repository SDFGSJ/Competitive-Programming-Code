//為什麼不用考慮down*1的情況? 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int obs[105];
int min(int a,int b){
	if(a>b)	return b;
	else	return a;
}
int main(void)
{
	int i;
	int t;
	scanf("%d",&t);
	while(t--){
		int ans=INT_MAX;
		int row,ver,hor;
		scanf("%d%d%d",&row,&ver,&hor);
		for(i=0;i<row;i++){
			scanf("%d",&obs[i]);
		}
		for(i=1;i<row;i++){
			int num=INT_MAX;
			if(obs[i]==obs[i-1]){	//如果正上方有obs 
				num=min(ver+hor,2*hor);
			}else if( abs(obs[i]-obs[i-1])==1 ){	//如果斜右上或斜左上有obs 
				num=min(ver,hor);
			}else{
				ans=0;
				break;
			}
			if(num<ans)	ans=num;
		}
		printf("%d\n",ans);
	}
	return 0;
}
