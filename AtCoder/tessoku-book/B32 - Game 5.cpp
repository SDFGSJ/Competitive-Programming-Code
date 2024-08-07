#include<bits/stdc++.h>
using namespace std;
int a[100010];
bool dp[100010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<=n;i++){
        bool result=false;
        for(int j=0;j<k;j++){
            if(i-a[j]>=0){
                result |= (!dp[i-a[j]]);
            }
        }
        dp[i]=result;
    }

    if(dp[n]){
        printf("First\n");
    }else{
        printf("Second\n");
    }
    return 0;
}