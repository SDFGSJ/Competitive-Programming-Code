#include<bits/stdc++.h>
using namespace std;
long long a,b,x;
bool valid(long long num){
    long long digit=to_string(num).size();
    return a*num+b*digit>x;
}
int main(){
    scanf("%lld%lld%lld",&a,&b,&x);

    long long L=0,R=1e9+1;
    while(L+1<R){
        long long mid=L+(R-L)/2;
        if(valid(mid)){
            R=mid;
        }else{
            L=mid;
        }
    }
    printf("%lld\n",L);
    return 0;
}
/*
bs
FF..FTT..T
L = pointer to the largest int whose price <= x
R = pointer to the smallest int whose price > x
*/