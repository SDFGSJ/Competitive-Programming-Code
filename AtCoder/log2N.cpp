#include<bits/stdc++.h>
using namespace std;
int main(){
    int i;
    long long n;
    scanf("%lld",&n);
    for(i=0 ; (long long)pow(2,i) <= n ; i++){ }
    printf("%d",i-1);
    return 0;
}