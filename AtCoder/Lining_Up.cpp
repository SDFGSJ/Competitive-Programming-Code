#include<bits/stdc++.h>
using namespace std;
int cnt[100010];
const int mod=1e9+7;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    }

    bool haveans=true;
    long long ans=1;
    if(n%2){
        haveans=(cnt[0]==1);
        for(int i=2;i<=n-1;i+=2){
            if(cnt[i]!=2){
                haveans=false;
                ans=0;
                break;
            }else{
                ans=(ans*cnt[i])%mod;
            }
        }
    }else{
        for(int i=1;i<=n-1;i+=2){
            if(cnt[i]!=2){
                haveans=false;
                ans=0;
                break;
            }else{
                ans=(ans*cnt[i])%mod;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
cnt[i] = cnt of num i
for each A_i, there exists 2 positions that results in this number
so if there are 3 or more nums with the same A_i, it's invalid
if n is odd, there should be 1 zero, 2 two, 2 four, 2 six..., check validity
if n is even, there should be 2 one, 2 three, 2 five..., check validity
the ans is pow(2,floor(n/2))
*/