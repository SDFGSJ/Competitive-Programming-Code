#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    scanf("%lld",&n);
    printf("%lld\n",n*(n-1+0)/2);
    return 0;
}
/*
the best permuation for {1,2,...N} is {2,3,...,N-1,N,1}
1%2 + 2%3 + (N-2)%(N-1) + (N-1)%N + N%1 = 1+2+...+(N-2)+(N-1)+0 = 0+1+...+(N-1) = N(N-1)/2
*/