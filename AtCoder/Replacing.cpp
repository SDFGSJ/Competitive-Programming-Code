#include<bits/stdc++.h>
using namespace std;
int cnt[100010];
int main(){
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
        sum+=num;
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int b,c;
        scanf("%d%d",&b,&c);
        sum=sum - 1ll*b*cnt[b] + 1ll*c*cnt[b];
        cnt[c]+=cnt[b];
        cnt[b]=0;
        printf("%lld\n",sum);
    }
    return 0;
}
/*
simulation
use an array to maintain the distribution of each number then do simulation
cnt[i] = # of i
*/