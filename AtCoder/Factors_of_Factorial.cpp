#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int cnt[1005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int tmp=i;
        for(int j=2;j*j<=tmp;j++){
            while(tmp%j==0){
                cnt[j]++;
                tmp/=j;
            }
        }
        if(tmp!=1){
            cnt[tmp]++;
        }
    }

    long long ans=1;
    for(int i=2;i<=n;i++){
        ans=ans*(cnt[i]+1)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
factorization
*/