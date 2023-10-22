#include<bits/stdc++.h>
using namespace std;
char m[1005][1005];
set<pair<int,int>> visited;   //set of coordinates of sensors
int dx[8]={-1, -1, 0, 1, 1, 1,  0, -1};
int dy[8]={ 0,  1, 1, 1, 0,-1, -1, -1};
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",m[i]);
    }
    int compo=0;
    queue<pair<int,int>> q;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(m[i][j]=='#' && visited.count(make_pair(i,j))==0){
                visited.emplace(i,j);
                q.emplace(i,j);
                while(!q.empty()){
                    auto pos=q.front();q.pop();
                    int x=pos.first;
                    int y=pos.second;

                    for(int k=0;k<8;k++){
                        if(0<=x+dx[k] && x+dx[k]<h && 0<=y+dy[k] && y+dy[k]<w
                            && m[x+dx[k]][y+dy[k]]=='#'
                            && visited.count(make_pair(x+dx[k], y+dy[k]))==0
                        ){
                            q.emplace(x+dx[k],y+dy[k]);
                            visited.emplace(x+dx[k],y+dy[k]);
                        }
                    }
                }
                compo++;
            }
        }
    }
    printf("%d\n",compo);
    return 0;
}