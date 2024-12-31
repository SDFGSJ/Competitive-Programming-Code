#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> stk;  //<val,cnt>
int main(){
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        if(!stk.empty() && stk.back().first==num){  //the val of the top is the same as num
            if(stk.back().second==num-1){   //the # of balls on top of the stack matches with the num written on it
                auto [val,cnt]=stk.back();stk.pop_back();
                ans-=cnt;
            }else{  //merge this ball with the top
                stk.back().second++;
                ans++;
            }
        }else{
            stk.emplace_back(num,1);
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
stack, use vector to simulate it
*/