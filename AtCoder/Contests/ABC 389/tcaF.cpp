#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x;
    scanf("%lld",&x);
    long long res=1,i;
    for(i=1;res!=x;i++){
        res*=i;
    }
    if(x==1){
        i=2;
    }
    printf("%lld\n",i-1);
    return 0;
}