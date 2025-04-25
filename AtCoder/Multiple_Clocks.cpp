#include<bits/stdc++.h>
using namespace std;
long long t[105];
int main(){
    int n;
    scanf("%d",&n);
    long long num=1;
    for(int i=0;i<n;i++){
        scanf("%lld",&t[i]);
        long long gcd=__gcd(num,t[i]);
        num=num/gcd*t[i];
    }
    printf("%lld\n",num);
    return 0;
}
/*
lcm(t[1],t[2]...t[n])
*/