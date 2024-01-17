#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long prefix[200010];
template<class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, long long x, FuncTy check){
    if(check(R,x) == false) return {R, R+1};
    if(check(L,x) == true) return {L-1, L};
    while(L+1 < R){
        Ty Mid = L + (R-L)/2;
        if(check(Mid,x)) R = Mid;
        else L = Mid;
    }
    return {L, R};
}
bool valid(int mid, long long x){
    return prefix[mid]>x;
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }

    for(int i=0;i<q;i++){
        long long x;
        scanf("%lld",&x);
        auto [L,R]=binarySearch(1,n,x,valid);
        printf("%d\n",L);
    }
    return 0;
}