#include<bits/stdc++.h>
using namespace std;
int a[100010],pre[100010],suf[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    pre[1]=a[1];
    for(int i=2;i<=n;i++){
        pre[i]=__gcd(pre[i-1],a[i]);
    }

    suf[n]=a[n];
    for(int i=n-1;i>=0;i--){
        suf[i]=__gcd(suf[i+1],a[i]);
    }

    int ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,__gcd(pre[i-1],suf[i+1]));
    }
    printf("%d\n",ans);
    return 0;
}
/*
prefix gcd
the problem is the same as "remove a[i] and find the max possible gcd of a[1 ~ i-1] and a[i+1 ~ n]"
maintain prefix, suffix gcd and enumerate each pos
prefix[i] = gcd of a[1] to a[i]
suffix[i] = gcd of a[n] to a[i]
ans = max{gcd(pre[i-1], suf[i+1]) for i=1 to n}
*/