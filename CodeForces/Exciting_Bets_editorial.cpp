#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(a==b){
            printf("0 0\n");
        }else{
            long long gcd = abs(a-b);
            long long dist = min(a%gcd,gcd-a%gcd);
            printf("%lld %lld\n",gcd,dist);
        }
    }
}