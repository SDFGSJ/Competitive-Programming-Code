#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ans=-1;
        scanf("%d",&n);
        //the max digit will be the answer
        while(n>0){
            ans=max(ans,n%10);
            n/=10;
        }
        printf("%d\n",ans);
    }
    return 0;
}