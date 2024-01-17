#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=n;i>=1;i--){
        v.emplace_back(i,0);
    }
    for(int i=0;i<q;i++){
        int type;
        scanf("%d",&type);
        if(type==1){
            char c;
            getchar();
            scanf("%c",&c);
            auto [x,y]=v.back();
            if(c=='U'){
                v.emplace_back(x,y+1);
            }else if(c=='D'){
                v.emplace_back(x,y-1);
            }else if(c=='L'){
                v.emplace_back(x-1,y);
            }else{
                v.emplace_back(x+1,y);
            }
        }else{
            int p;
            scanf("%d",&p);
            printf("%d %d\n",v[v.size()-p].first, v[v.size()-p].second);
        }
    }
    return 0;
}