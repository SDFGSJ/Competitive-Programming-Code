#include<bits/stdc++.h>
using namespace std;
pair<long long,int> katana[100010];   //<throw,wield>
int main(){
    int n,h;
    scanf("%d%d",&n,&h);
    int maxa=-1;
    for(int i=1;i<=n;i++){
        int a;long long b;
        scanf("%d%lld",&a,&b);
        katana[i]={b,a};
        maxa=max(maxa,a);
    }

    sort(katana+1,katana+1+n,greater<>());  //throw the katana with the larger b first
    for(int i=1;i<=n;i++){
        katana[i].first+=katana[i-1].first;
    }

    long long ans=LONG_LONG_MAX;
    for(int i=0;i<=n;i++){  //we can throw 0 to n katana at last
        long long thr=katana[i].first, remainHP=max(h-thr,0ll);
        ans=min(ans,i + (remainHP+maxa-1)/maxa);    //throw i katanas + wield "ceil(remainHP / maxa)" times
    }
    printf("%lld\n",ans);
    return 0;
}
/*
greedy
we always wield the katana with the max a[i], then we throw katanas from the largest b values
since we can throw 0 to N katanas, sort b[i] desc and calc b's prefix sum
*/