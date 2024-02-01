#include<bits/stdc++.h>
using namespace std;
int digits(long long num){
    int cnt=0;
    while(num){
        cnt++;
        num/=10;
    }
    return cnt;
}
int main(){
    long long n;
    scanf("%lld",&n);

    int ans=100;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            ans=min(ans,max(digits(i),digits(n/i)));
        }
    }
    printf("%d\n",ans);
    return 0;
}