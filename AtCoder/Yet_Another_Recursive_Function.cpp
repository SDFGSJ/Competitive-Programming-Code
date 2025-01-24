#include<bits/stdc++.h>
using namespace std;
unordered_map<long long,long long> um;  //<x,f(x)>
long long f(long long num){
    if(um.find(num)!=um.end()){
        return um[num];
    }
    um[num]=f(num/2)+f(num/3);
    return um[num];
}
int main(){
    long long N;
    scanf("%lld",&N);
    um[0]=1;
    printf("%lld\n",f(N));
    return 0;
}
/*
recursion + memoization
*/