#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> nxt;
unordered_map<string,int> indeg;
unordered_set<string> vis;
bool has_cycle(string start){
    string now=start;
    while(nxt.find(now)!=nxt.end()){
        if(vis.find(now)==vis.end()){
            vis.emplace(now);
            now=nxt[now];
        }else{
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string s,t;
        cin>>s>>t;
        nxt[s]=t;
        indeg[t]++;
    }

    bool indeg_has_zero=false;
    string ans="Yes";
    for(auto [from,to]:nxt){
        if(nxt[to]==from){
            ans="No";
        }
        int deg=indeg[from];
        if(deg==0){
            indeg_has_zero=true;
            if(has_cycle(from)){
                ans="No";
            }
        }
    }
    if(!indeg_has_zero){
        ans="No";
    }
    cout<<ans<<'\n';
    return 0;
}
/*
if contain cycle, then no
special case: a->b, b->a
if all indeg=0 => no
else => yes?
*/