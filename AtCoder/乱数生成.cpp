#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    scanf("%lld%lld",&n,&k);

    long long three_diff=(k-1)*(n-k), two_same=n-1, three_same=1;
    printf("%.15Lf\n",(long double)(three_diff*6+two_same*3+three_same) / (n*n*n));
    return 0;
}
/*
consider 3 diff, 2 same 1 diff, 3 same
there are k-1 numbers that are < k, n-k numbers > k
3 diff => pick 1 number < k, and 1 number > k. There are 3! permutation of this kind
2 same 1 diff => (k,k,x) where x=1 to n except k. There are 3 permutation of this kind
3 same => (k,k,k)
*/