#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int remain=k-i-j;
            if(1<=remain && remain<=n){
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}