#include<bits/stdc++.h>
using namespace std;
const int mod=1e9;
long long a[1000010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<=k-1){ //n is in the first k elements, the ans is 1
        printf("1\n");
        return 0;
    }
    long long ans=0;
    for(int i=0;i<k;i++){
        a[i]=1;
        ans+=1;
    }
    //now ans = sum of a[0..k-1], which is the value of a[k]
    for(int i=k;i<n;i++){
        a[i]=ans;
        ans-=a[i-k];
        ans+=a[i];
        ans=(ans%mod+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
sliding window
calc the diff from previous result to get current result
*/