#include<bits/stdc++.h>
using namespace std;
int main(){
    long long b;
    scanf("%lld",&b);

    bool ok=false;
    long long num=1ll;
    while(1){
        long long result=1ll;
        for(int i=0;i<num;i++){
            result*=num;
        }
        if(result==b){
            ok=true;
            break;
        }
        if(result>b){
            break;
        }
        num++;
    }

    if(ok){
        printf("%lld\n",num);
    }else{
        printf("-1\n");
    }
    return 0;
}