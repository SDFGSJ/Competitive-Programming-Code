#include<bits/stdc++.h>
using namespace std;
int H,W;
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
bool ingrid(int r,int c){
    return 1<=r && r<=H && 1<=c && c<=W;
}
string bfs(int startr,int startc,
    vector<string>& grid,
    vector<vector<pair<int,int>>>& prede
){
    queue<pair<int,int>> q;
    q.emplace(startr,startc);
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nextr=r+dx[i],nextc=c+dy[i];
            if(ingrid(nextr,nextc) && grid[nextr][nextc]=='.' && prede[r][c]!=make_pair(nextr,nextc)){
                if(prede[nextr][nextc]==make_pair(-1,-1)){
                    q.emplace(nextr,nextc);
                    prede[nextr][nextc]={r,c};
                }else{
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
int main(){
    int sr=0,sc=0;
    scanf("%d%d",&H,&W);
    vector<string> grid(H+1);
    for(int i=1;i<=H;i++){
        cin>>grid[i];
        grid[i]=' '+grid[i];
        for(int j=1;j<=W;j++){
            if(grid[i][j]=='S'){
                sr=i,sc=j;
                break;
            }
        }
    }

    vector<vector<pair<int,int>>> prede(H+1, vector<pair<int,int>>(W+1,{-1,-1}));
    prede[sr][sc]={sr,sc};
    string ans=bfs(sr,sc,grid,prede);
    cout<<ans<<'\n';
    return 0;
}
/*
WA on sample 3
*/