#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
bool case1(long long dx,long long dy){
    return (dx==dy) && max(1-a,1-b)<=dx && dx<=min(n-a,n-b);
}
bool case2(long long dx,long long dy){
    long long L=max(1-a,b-n), R=min(n-a,b-1);
    return (dx==-dy) && ((L<=dx && dx<=R) || (L<=dy && dy<=R));
}
int main(){
    long long p,q,r,s;
    scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&a,&b,&p,&q,&r,&s);

    for(long long i=p;i<=q;i++){
        for(long long j=r;j<=s;j++){
            long long dx=i-a,dy=j-b;
            if(case1(dx,dy) || case2(dx,dy)){
                printf("#");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
/*
enumerate points (i,j) where i in [P,Q], j in [R,S], check whether they are black or not
find delta_x and delta_y between (i,j) and (A,B)
*/