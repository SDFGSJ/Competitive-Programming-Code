#include<bits/stdc++.h>
using namespace std;
int x[1005],y[1005];
struct myhash{
    size_t operator()(const pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};
unordered_set<pair<int,int>,myhash> vis,black;
int dx[6]={-1,-1,0,0,1,1},dy[6]={-1,0,-1,1,0,1};
int n;
void bfs(int idx){
    int sr=x[idx],sc=y[idx];
    queue<pair<int,int>> q;
    q.emplace(sr,sc);
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        if(vis.find({r,c})!=vis.end()){
            continue;
        }
        vis.emplace(r,c);
        for(int i=0;i<6;i++){
            int nr=r+dx[i], nc=c+dy[i];
            if(black.find({nr,nc})!=black.end()){
                q.emplace(nr,nc);
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
        black.emplace(x[i],y[i]);
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        if(vis.find({x[i],y[i]})==vis.end()){
            bfs(i);
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
/*
bfs + unordered set with hash function
vis contains the block that has been visited
black contains the block that is colored black

Note: in order to prevent negative coordinates, we can shift them by a constant initially
and use 2D array instead of hash set
*/