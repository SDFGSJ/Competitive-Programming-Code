#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
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
        }else if(op==2){
            if(!s.empty()){
                printf("%d\n",*s.begin());
                s.erase(s.begin());
            }else{
                printf("%d\n",que.front());
                que.pop();
            }
        }else{
            while(!que.empty()){
                int num=que.front();que.pop();
                s.emplace(num);
            }
        }
    }
    return 0;
}
/*
divide A into 2 parts, multiset | queue
1 => push element into queue
2 => if multiset is not empty, print the 1st element of multiset and pop it
    else print the 1st element of queue and pop it
3 => push all elements in queue into multiset
*/