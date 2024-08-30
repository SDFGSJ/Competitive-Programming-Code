#include<bits/stdc++.h>
using namespace std;
int cnt[2010];
int main(){
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int dist=min(j-i, abs(y-j)+1+abs(x-i));
            cnt[dist]++;
        }
    }
    for(int i=1;i<=n-1;i++){
        printf("%d\n",cnt[i]);
    }
    return 0;
}
/*
enumerate start(i) and end(j) point
consider whether or not use the edge x->y, we have 2 ways to go from i to j
1. i->j
2. i->x->y->j
*/