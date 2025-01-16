#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int>> dq; //<val,cnt>
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int op,x,c;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&x,&c);
            dq.emplace_back(x,c);
        }else{
            scanf("%d",&c);
            int balls=0;    //# of balls we have already taken
            long long ans=0;
            while(balls<c){
                auto [val,cnt]=dq.front();dq.pop_front();
                if(balls+cnt<=c){   //take all the balls from this pair
                    ans+=1ll*val*cnt;
                    balls+=cnt;
                }else{  //we need (c-balls) more balls and put the remaining balls back to deque
                    ans+=1ll*val*(c-balls);
                    dq.emplace_front(val,cnt-(c-balls));
                    balls=c;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
deque
*/