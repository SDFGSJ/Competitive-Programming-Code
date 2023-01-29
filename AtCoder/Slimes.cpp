#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,k;
    int cnt=0;
    scanf("%lld%lld%lld",&a,&b,&k);
    while(a<b){
        a*=k;
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}