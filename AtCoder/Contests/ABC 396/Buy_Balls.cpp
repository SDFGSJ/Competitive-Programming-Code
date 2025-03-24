#include<bits/stdc++.h>
using namespace std;
int black[200010],white[200010];
long long bpre[200010],wpre[200010],bsufmax[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&black[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&white[i]);
    }

    sort(black+1,black+1+n,greater<>());
    sort(white+1,white+1+m,greater<>());

    for(int i=1;i<=n;i++){  //black prefix sum
        bpre[i]=bpre[i-1]+black[i];
    }
    for(int i=1;i<=m;i++){  //white prefix sum
        wpre[i]=wpre[i-1]+white[i];
    }

    bsufmax[n]=bpre[n]; //black suffix max
    for(int i=n-1;i>=0;i--){
        bsufmax[i]=max(bsufmax[i+1],bpre[i]);
    }

    long long ans=LONG_LONG_MIN;
    for(int i=0;i<=min(n,m);i++){   //take i white balls, need to take >=i black balls
        ans=max(ans,wpre[i]+bsufmax[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
enumerate the # of white balls taken(white prefix sum[i])
find the max value when choosing at least i black balls(sort desc, max suffix sum[i])
*/