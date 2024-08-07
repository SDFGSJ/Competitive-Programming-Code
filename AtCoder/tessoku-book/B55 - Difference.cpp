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
        }else{
            int ans=2e9;
            auto it=s.upper_bound(x);
            if(it!=s.end()){
                ans=min(ans, abs(x-*it));
            }
            if(it!=s.begin()){
                ans=min(ans, abs(x-*prev(it)));
            }
            if(s.size()==0){
                ans=-1;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}