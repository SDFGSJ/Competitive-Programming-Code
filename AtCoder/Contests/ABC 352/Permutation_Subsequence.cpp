#include<bits/stdc++.h>
using namespace std;
int a[200010],idx[200010];
set<int> sw;    //sliding window
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        idx[a[i]]=i;
    }
    for(int i=1;i<=k;i++){
        sw.emplace(idx[i]);
    }

    int ans=1e9;
    for(int i=k+1;i<=n+1;i++){
        int idxmax = *sw.rbegin();
        int idxmin = *sw.begin();
        //printf("max=%d, min=%d\n",idxmax,idxmin);
        int diff=idxmax-idxmin;
        ans=min(ans,diff);
        sw.erase(sw.find(idx[i-k]));    //remove the leftmost number of the window
        sw.emplace(idx[i]); //add next number
    }
    printf("%d\n",ans);
    return 0;
}