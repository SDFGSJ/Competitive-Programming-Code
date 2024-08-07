#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    scanf("%lld",&n);
    printf("%lld\n",n/3+n/5+n/7-n/15-n/21-n/35+n/105);
    return 0;
}