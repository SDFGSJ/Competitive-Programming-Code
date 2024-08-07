#include<bits/stdc++.h>
using namespace std;
const int mod=(int)1e9+7;
int sum[105];
int main(){
    int n;
    scanf("%d",&n);
    long long ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            int num;
            scanf("%d",&num);
            sum[i]+=num;
        }
        ans=(ans*sum[i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}