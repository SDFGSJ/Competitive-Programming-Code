#include<bits/stdc++.h>
using namespace std;
int cnt[200010];
set<pair<int,int>> s;   //<vote cnt, id>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        s.emplace(0,-(i+1));
    }
    /*for(auto i:s){
        printf("(%d %d)\n",i.first,i.second);
    }*/
    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        auto iter=s.lower_bound(make_pair(cnt[num], -num));
        //printf("iter = (%d, %d)\n",iter->first,iter->second);
        s.erase(iter);
        s.emplace(cnt[num]+1, -num);
        cnt[num]+=1;
        /*printf("s=[");
        for(auto i:s){
            printf("(%d %d), ",i.first,i.second);
        }
        printf("]\n");*/
        printf("%d\n",-s.rbegin()->second);
    }
    return 0;
}