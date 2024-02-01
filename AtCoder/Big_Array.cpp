#include<bits/stdc++.h>
using namespace std;
long long num[100010],pre[200010];  //number i appear num[i] times
int main(){
    int n;
    long long k;
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        num[a]+=b;
    }

    for(int i=1;i<=100000;i++){
        pre[i]=pre[i-1]+num[i];
        if(pre[i]>=k){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}