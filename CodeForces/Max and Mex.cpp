#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}
int num[100010];
int main(void)
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n,op;
		int mex=0,max=0;
		int find=0,repeat=0;
		
		scanf("%d%d",&n,&op);
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		if(op==0){
			printf("%d\n",n);
			continue;
		}
		
		qsort(num,n,sizeof(int),cmp);
		for(i=0;i<n;i++){
			if(num[i]!=i){
				mex=i;
				find=1;
				break;
			}
		}
		if(!find)	mex=n;
		max=num[n-1];
		int result=(int)ceil( (mex+max)/2.0);
		//printf("mex=%d,max=%d,result=%d\n",mex,max,(int)ceil( (mex+max)/2.0) );
		
		for(i=0;i<n && num[i]<=result;i++){
			if(num[i]==result){
				repeat=1;
			}
		}
		
		if(mex>max){
			printf("%d\n",n+op);
		}else if(mex<max){
			if(repeat){
				printf("%d\n",n);
			}else{
				printf("%d\n",n+1);
			}
		}
	}
	return 0;
}
