#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0,i;
    long long d,x,y;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++){
        scanf("%lld%lld",&x,&y);
        if(x*x+y*y<=d*d){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}