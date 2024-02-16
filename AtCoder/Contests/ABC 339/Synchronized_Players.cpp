#include<bits/stdc++.h>
using namespace std;
char grid[65][65];
queue<tuple<int,int,int,int,int>> q;    //<p1 x,p1 y,p2 x,p2 y,steps>
set<tuple<int,int,int,int>> s;
vector<pair<int,int>> player;
int dx[4]={-1,0,1,0};   //URDL
int dy[4]={0,1,0,-1};
bool ingrid(int x,int y,int n){
    return (0<=x && x<n && 0<=y && y<n);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",grid[i]);
        for(int j=0;j<n;j++){
            if(grid[i][j]=='P'){
                player.emplace_back(i,j);
            }
        }
    }

    q.emplace(player[0].first, player[0].second, player[1].first, player[1].second, 0);
    s.emplace(player[0].first, player[0].second, player[1].first, player[1].second);
    while(!q.empty()){
        int p1x,p1y,p2x,p2y,step;
        tie(p1x,p1y,p2x,p2y,step)=q.front();q.pop();

        if(p1x==p2x && p1y==p2y){
            printf("%d\n",step);
            return 0;
        }

        int p1_blocked=0,p2_blocked=0;
        for(int i=0;i<4;i++){
            int new_p1x=p1x, new_p1y=p1y, new_p2x=p2x, new_p2y=p2y;
            if(ingrid(p1x+dx[i], p1y+dy[i], n) && grid[p1x+dx[i]][p1y+dy[i]]!='#'){
                new_p1x=p1x+dx[i];
                new_p1y=p1y+dy[i];
            }else{
                p1_blocked++;
            }
            if(ingrid(p2x+dx[i], p2y+dy[i], n) && grid[p2x+dx[i]][p2y+dy[i]]!='#'){
                new_p2x=p2x+dx[i];
                new_p2y=p2y+dy[i];
            }else{
                p2_blocked++;
            }
            if(s.find({new_p1x,new_p1y,new_p2x,new_p2y})==s.end()){
                s.emplace(new_p1x,new_p1y,new_p2x,new_p2y);
                q.emplace(new_p1x,new_p1y,new_p2x,new_p2y,step+1);
            }
        }
        if(p1_blocked==4 || p2_blocked==4){
            printf("-1\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}