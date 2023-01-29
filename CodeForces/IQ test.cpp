#include<stdio.h>
#include<stdbool.h>
int num[105];
bool iseven[105];
int main(void)
{
	int i;
	int n,ans=0,true_cnt=0,false_cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(num[i]%2==0){
			iseven[i]=true;
			true_cnt++;
		}else{
			iseven[i]=false;
			false_cnt++;
		}
	}
	//printf("true_cnt=%d,false_cnt=%d\n",true_cnt,false_cnt);
	if(true_cnt==1){
		for(i=0;i<n;i++){
			if(iseven[i]==true){
				ans=i+1;
				break;
			}
		}
	}else{
		for(i=0;i<n;i++){
			if(iseven[i]==false){
				ans=i+1;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
