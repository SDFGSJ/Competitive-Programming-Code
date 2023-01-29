#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int walk=min(abs(n-k),abs(k-1))+(n-1);  //total number of step
    int move=2+(n-1);
    int pick=n; //n coins have to pick n times
    int ans=walk+move+pick;
    printf("%d\n",ans);
    return 0;
}