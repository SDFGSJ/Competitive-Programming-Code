#include<bits/stdc++.h>
using namespace std;
long long cnt[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    }

    long long ans=0;
    for(int i=1;i<=100;i++){
        if(cnt[i]>=3){
            ans+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
        }
    }
    printf("%lld\n",ans);
    return 0;
}