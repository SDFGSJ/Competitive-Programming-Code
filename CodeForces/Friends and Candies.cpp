#include<bits/stdc++.h>
using namespace std;
int candy[200010];
int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		int n,sum=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&candy[i]);
			sum+=candy[i];
		}
		if(sum%n!=0){
			printf("-1\n");
			continue;
		}else{
			int ave=sum/n,ans=0;
			for(i=0;i<n;i++){
				if(candy[i]>ave){
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
