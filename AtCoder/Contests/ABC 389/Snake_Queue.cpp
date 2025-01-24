#include<bits/stdc++.h>
using namespace std;
deque<pair<long long,int>> dq;  //<coor,len>
long long offset;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int l;
            scanf("%d",&l);
            if(dq.empty()){
                dq.emplace_back(0,l);
            }else{
                auto [last_coor, last_len]=dq.back();
                dq.emplace_back(last_coor+last_len,l);
            }
        }else if(op==2){
            offset+=dq.front().second;
            dq.pop_front();
        }else{
            int k;
            scanf("%d",&k);
            k--;
            printf("%lld\n",dq[k].first-offset);
        }
    }
    return 0;
}
/*
deque
use a pair to maintain its head coordinate and length

type 2 operation is equivalent to minus every head coordinates with a constant
so we maintain an "offset" variable and update it when a snake leaves
*/