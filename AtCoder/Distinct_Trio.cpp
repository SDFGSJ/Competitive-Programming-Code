#include<bits/stdc++.h>
using namespace std;
long long cnt[200010];
long long nC3(int n){
    return 1ll*n*(n-1)*(n-2)/6;
}
long long nC2(int n){
    return 1ll*n*(n-1)/2;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    }

    long long ans=nC3(n);
    for(int i=1;i<=200000;i++){
        if(cnt[i]>=3){
            ans-=nC3(cnt[i]);
        }
        if(cnt[i]>=2){
            ans-=nC2(cnt[i])*(n-cnt[i]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
cnt[i] = # of i's

# of all possible triples = C(n,3)
ans is C(n,3) - (2 same, 1 diff) - (3 same)
# of (2 i's, 1 diff other than i) = C(cnt[i],2) * (n-cnt[i]) when cnt[i] >= 2
# of (3 i's) = C(cnt[i],3) when cnt[i] >= 3
*/