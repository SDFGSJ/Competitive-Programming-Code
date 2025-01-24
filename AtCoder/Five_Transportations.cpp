#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
    long long n,bottleneck=LONG_LONG_MAX;
    scanf("%lld",&n);
    for(int i=0;i<5;i++){
        scanf("%lld",&a[i]);
        bottleneck=min(bottleneck,a[i]);
    }

    printf("%lld\n",5 + (n+bottleneck-1)/bottleneck - 1);
    return 0;
}
/*
suppose the bottleneck appears at the middle
where bottleneck = the smallest capacity among 5 vehicles
then after passengers pass thru the bottleneck, no matter how much capacity the latter vehicles can carry
those vehicles could only carry "bottleneck" people
so we can divide N people into groups of size "bottleneck"
when t=5, the 1st group reach city 6
and we need (# of groups)-1 minutes for the last group to reach city 6
hence the ans is 5 + ceil(N/bottleneck) - 1
*/