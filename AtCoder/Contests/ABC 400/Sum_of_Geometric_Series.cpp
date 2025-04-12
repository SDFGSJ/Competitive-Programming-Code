#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    int m;
    scanf("%lld%d",&n,&m);

    long long ans=0,num=1;
    for(int i=0;i<=m;i++){
        ans+=num;
        if(ans>(int)1e9){
            printf("inf\n");
            return 0;
        }
        num*=n;
    }
    printf("%lld\n",ans);
    return 0;
}