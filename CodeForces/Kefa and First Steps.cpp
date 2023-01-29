#include<stdio.h>
int num[100005];
int asc[100005];
int main(void)
{
	int i;
	int n,cnt=1,max=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	asc[0]=cnt,cnt++;
	for(i=1;i<n;i++){
		if(num[i]>=num[i-1]){
			asc[i]=cnt,cnt++;
		}else{
			cnt=1;
			asc[i]=cnt,cnt++;
		}
	}
	for(i=0;i<n;i++){
		//printf("%d,",asc[i]);
		if(asc[i]>max){
			max=asc[i];
		}
	}
	//printf("\n");
	printf("%d\n",max);
	
	return 0;
}
