#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long mypow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int w,h;
    scanf("%d%d",&w,&h);

    long long nomi=1,denomi=1;   //nominator/denominator
    for(int i=w;i<=h+w-2;i++){
        nomi=nomi*i%mod;
    }
    for(int i=1;i<=h-1;i++){
        denomi=denomi*i%mod;
    }
    printf("%lld\n",nomi*mypow(denomi,mod-2)%mod);
    return 0;
}
/*
the bottom-left / top-right coordinate of the grid is (1,1) / (W,H)
there's only 1 way to reach (1~W, 1), (1, 1~H) from (1,1), so we mark them 1
and we find out that the whole grid becomes a pascal triangle, hence we can find the ans using C(n,m)

To walk from (1,1) to (W,H), we need (W-1) horizontal moves and (H-1) vertical moves,
and all permutation of these H+W-2 moves = the # of ways to reach (W,H) from (1,1) = C(H+W-2, W-1) = C(H+W-2,H-1)
*/