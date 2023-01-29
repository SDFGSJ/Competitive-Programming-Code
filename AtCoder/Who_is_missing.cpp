#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num,i;
    long long sum=0;
    scanf("%d",&n);
    for(i=0;i<4*n-1;i++){
        scanf("%d",&num);
        sum+=num;
    }
    printf("%lld\n",2ll*n*(n+1) - sum);
    return 0;
}