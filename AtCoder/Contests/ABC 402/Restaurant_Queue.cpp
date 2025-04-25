#include<bits/stdc++.h>
using namespace std;
queue<int> que;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            que.emplace(x);
        }else{
            int num=que.front();que.pop();
            printf("%d\n",num);
        }
    }
    return 0;
}