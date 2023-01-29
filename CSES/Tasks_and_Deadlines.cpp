#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int>> v;    //<duration,deadline>
    int n;
    scanf("%d",&n);
    while(n--){
        int dura,dead;
        scanf("%d%d",&dura,&dead);
        v.emplace_back(dura,dead);
    }

    long long ans=0,now=0;
    sort(v.begin(),v.end());    //sort by duration,always pick the smallest
    for(auto i:v){
        now+=i.first;
        ans+=i.second-now;
    }
    printf("%lld\n",ans);
    return 0;
}