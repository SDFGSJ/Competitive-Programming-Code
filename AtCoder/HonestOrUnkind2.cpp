#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> testi[20];    //<person id,type>
int calc(int n,int bitmask){
    bool contradict=false;
    for(int i=0;i<n;i++){   //for each person
        if((bitmask>>i)&1){ //i-th person is kind
            for(auto [person,type]:testi[i]){
                if(((bitmask>>person)&1) ^ type){   //not consistent
                    contradict=true;
                }
            }
        }
    }
    if(contradict){
        return 0;
    }
    return __builtin_popcount(bitmask);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int ai;
        scanf("%d",&ai);
        for(int j=0;j<ai;j++){
            int x,y;
            scanf("%d%d",&x,&y);
            x--;    //person id is 0-indexed
            testi[i].emplace_back(x,y);
        }
    }

    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        ans=max(ans,calc(n,bit));
    }
    printf("%d\n",ans);
    return 0;
}
/*
bitmask enumeration
ith bit = 1 if person i is kind
only check the testimony of kind people
since the testimonies of an unkind person may be correct or not, so it's "dont care"
*/