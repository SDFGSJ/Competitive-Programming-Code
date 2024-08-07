#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    scanf("%lld",&n);
    int ans=0;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            for(long long j=i;j*j<=n/i;j++){
                if(n/i%j==0){
                    ans++;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}