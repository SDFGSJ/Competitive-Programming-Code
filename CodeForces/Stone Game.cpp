#include<bits/stdc++.h>
using namespace std;
int stone[105];
int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n,ans=0;
		int min=101,max=-1,minidx=0,maxidx=0;
		int a,b,c;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&stone[i]);
			if(stone[i]<min){
				min=stone[i];
				minidx=i;
			}
			if(stone[i]>max){
				max=stone[i];
				maxidx=i;
			}
		}
		
		//printf("minidx=%d,maxidx=%d\n",minidx,maxidx);
		if(minidx<maxidx){
			a=minidx,b=maxidx-minidx-1,c=n-1-maxidx;
		}else{
			a=maxidx,b=minidx-maxidx-1,c=n-1-minidx;
		}
		//printf("a=%d,b=%d,c=%d\n",a,b,c);
		if(a<c){
			ans+=a;
			if(b<c){
				ans+=b;
			}else{
				ans+=c;
			}
		}else{
			ans+=c;
			if(a<b){
				ans+=a;
			}else{
				ans+=b;
			}
		}
		printf("%d\n",ans+2);
	}
	return 0;
}
