#include<stdio.h>
#include<string.h>
int lv[105];
int exist[105];
int main(void)
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(exist,0,sizeof(exist));
		for(i=0;i<n;i++){
			scanf("%d",&lv[i]);
			exist[lv[i]]++;
		}
		for(i=0;i<105;i++){
			if(exist[i]!=0){
				break;
			}
		}
		printf("%d\n",n-exist[i]);	//�̤p�����s�H�@�w���|Ĺ
	}
	return 0;
}
