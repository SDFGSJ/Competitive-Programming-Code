#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s,k,sum=0;
    scanf("%d%d%d",&n,&s,&k);
    for(int i=0;i<n;i++){
        int p,q;
        scanf("%d%d",&p,&q);
        sum+=p*q;
    }
    if(sum<s){
        sum+=k;
    }
    printf("%d\n",sum);
    return 0;
}