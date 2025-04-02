#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> nxt;
unordered_set<string> users;
unordered_set<string> vis;
bool has_cycle(string start){
    unordered_set<string> path;
    string now=start;
    while(1){
        if(path.find(now)!=path.end()){ //encounter this node twice => has cycle
            return true;
        }
        path.emplace(now);

        if(vis.find(now)!=vis.end()){   //this node has been visited, no need to traverse further
            break;
        }
        vis.emplace(now);

        if(nxt.find(now)==nxt.end()){   //reach the end of this linked list
            break;
        }
        now=nxt[now];
    }
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string s,t;
        cin>>s>>t;
        users.emplace(s),users.emplace(t);
        nxt[s]=t;
    }

    for(auto user:users){
        if(vis.find(user)==vis.end()){
            bool res=has_cycle(user);
            if(res){
                printf("No\n");
                exit(0);
            }
        }
    }
    printf("Yes\n");
    return 0;
}
/*
if contain cycle, then no
special case: a->b, b->a
Editorial video watched
*/