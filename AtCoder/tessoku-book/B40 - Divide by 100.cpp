#include<bits/stdc++.h>
using namespace std;
int cnt[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        cnt[num%100]++;
    }

    long long ans=0;
    ans+=1ll*cnt[0]*(cnt[0]-1)/2;
    for(int i=1;i<=49;i++){
        ans+=1ll*cnt[i]*cnt[100-i];
    }
    ans+=1ll*cnt[50]*(cnt[50]-1)/2;
    printf("%lld\n",ans);
    return 0;
}