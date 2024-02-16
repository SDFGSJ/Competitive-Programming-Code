#include<bits/stdc++.h>
using namespace std;
set<string> visited;
int main(){
    string s;
    cin>>s;

    queue<pair<string,int>> q;    //<string,step>
    visited.emplace(s);
    q.emplace(s,0);
    while(!q.empty()){
        auto [str,step]=q.front();q.pop();

        if(str=="atcoder"){
            printf("%d\n",step);
            return 0;
        }

        for(int i=0;i+1<s.length();i++){
            string clone=str;
            swap(clone[i],clone[i+1]);
            if(!visited.count(clone)){
                visited.emplace(clone);
                q.emplace(clone,step+1);
            }
        }
    }
    return 0;
}