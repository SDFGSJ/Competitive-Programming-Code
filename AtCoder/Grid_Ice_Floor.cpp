#include<bits/stdc++.h>
using namespace std;
char grid[205][205];
bool visited[205][205];
queue<pair<int,int>> q;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",grid[i]);
    }

    q.emplace(1,1);
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        if(visited[x][y]){
            continue;
        }
        visited[x][y]=true;
        for(int i=0;i<4;i++){   //try all 4 directions
            int tmpx=x,tmpy=y;
            while(grid[tmpx][tmpy]!='#'){   //walk until we meet '#'
                grid[tmpx][tmpy]='o';
                tmpx+=dx[i];
                tmpy+=dy[i];
            }
            tmpx-=dx[i];    //currently on '#', move back 1 cell
            tmpy-=dy[i];
            q.emplace(tmpx,tmpy);   //emplace this corner
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='o'){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}