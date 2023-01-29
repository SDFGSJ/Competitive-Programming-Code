#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnt[105];
int main(void)
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		memset(cnt,0,sizeof(cnt));
		int n,num;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&num);
			cnt[num]++;
		}
		for(i=0;i<105;i++){
			if(cnt[i]>0){
				printf("%d ",i);
				cnt[i]--;
			}
		}
		for(i=0;i<105;i++){
			if(cnt[i]>0){
				while(cnt[i]--){
					printf("%d ",i);
				}
			}
		}
		printf("\n");
		/*for(i=0;i<105;i++){
			printf("%d,",cnt[i]);
		}
		printf("\n");*/
	}
	return 0;
}
