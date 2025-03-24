#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int main(){
    for(int i=0;i<100;i++){
        s.emplace(0);
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            s.emplace(x);
        }else{
            printf("%d\n",s.top());
            s.pop();
        }
    }
    return 0;
}