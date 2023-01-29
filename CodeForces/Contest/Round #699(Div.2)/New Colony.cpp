#include<stdio.h>
int m[105];
int main(void)
{
	int t,i,j,k;
	int moun,rock,now,des;
	scanf("%d",&t);
	while(t--){
		des=0;
		scanf("%d%d",&moun,&rock);
		for(i=0;i<moun;i++){
			scanf("%d",&m[i]);
		}
		while(rock--){
			now=0;
			for(i=0;i<moun-1;i++){
				if(m[i]<m[i+1]){
					break;
				}
			}
			if(i==moun-1){
				des=1;
			}
			if(des){
				break;
			}
			for(i=0;i<moun-1;i++){
				if(m[i]>=m[i+1]){
					now++;
					//m[i+1]++;
				}else{
					m[i]++;
					break;
				}
			}
		}
		/*printf("after=");
		for(i=0;i<moun;i++){
			printf("%d ",m[i]);
		}*/
		if(des){
			printf("-1\n");
		}else{
			printf("%d\n",now+1);
		}
	}
	return 0;
}
