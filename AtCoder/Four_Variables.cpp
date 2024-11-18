#include<bits/stdc++.h>
using namespace std;
int divcnt[200010];
int countdiv(int num){
    int res=0;
    for(int i=1;i*i<=num;i++){
        if(num%i==0){
            if(i*i==num){
                res++;
            }else{
                res+=2;
            }
        }
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        divcnt[i]=countdiv(i);
    }

    long long ans=0;
    for(int i=1;i<=n-1;i++){
        ans+=1ll*divcnt[i]*divcnt[n-i];
    }
    printf("%lld\n",ans);
    return 0;
}
/*
AB+CD=N, enumerate AB from 1 to n-1
precalculate divcnt[i] to be the # of divisor of i
ans is sum(divcnt[i]*divcnt[n-i]) for i from 1 to n-1
*/