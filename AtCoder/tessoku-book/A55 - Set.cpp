#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==1){
            s.emplace(x);
        }else if(op==2){
            s.erase(s.find(x));
        }else{
            auto it=s.lower_bound(x);
            if(it==s.end()){
                printf("-1\n");
            }else{
                printf("%d\n",*it);
            }
        }
    }
    return 0;
}