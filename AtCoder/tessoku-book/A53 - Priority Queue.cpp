#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            pq.push(x);
        }else if(op==2){
            printf("%d\n",pq.top());
        }else{
            pq.pop();
        }
    }
    return 0;
}