#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1}; //URDL
int h,w;
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
queue<tuple<int,int,int>> q;    //<r,c,dir>
int distH[1005][1005],distV[1005][1005];
int main(){
    int sr,sc,gr,gc;    //S at (sr,sc), G at (gr,gc)
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='S'){
                sr=i,sc=j;
            }
            if(grid[i][j]=='G'){
                gr=i,gc=j;
            }
        }
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            distH[i][j]=distV[i][j]=INT_MAX;
        }
    }

    q.emplace(sr,sc,-1);    //The direction of the first move can be chosen arbitrarily.
    distH[sr][sc]=distV[sr][sc]=0;
    while(!q.empty()){
        int nowr,nowc,nowdir;
        tie(nowr,nowc,nowdir)=q.front();q.pop();

        for(int i=0;i<4;i++){
            if((i%2) != nowdir){    //the next dir is different from the current dir
                int nextr=nowr+dx[i], nextc=nowc+dy[i];
                if(!ingrid(nextr,nextc)){
                    continue;
                }
                if(grid[nextr][nextc]=='#'){
                    continue;
                }

                if(i%2){    //horizontal
                    if(distH[nextr][nextc]==INT_MAX){
                        distH[nextr][nextc]=distV[nowr][nowc]+1;
                        q.emplace(nextr,nextc,i%2);
                    }
                }else{
                    if(distV[nextr][nextc]==INT_MAX){
                        distV[nextr][nextc]=distH[nowr][nowc]+1;
                        q.emplace(nextr,nextc,i%2);
                    }
                }
            }
        }
    }

    int ans=min(distH[gr][gc], distV[gr][gc]);
    if(ans==INT_MAX){   //cant reach G
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}
/*
bfs
distH[i][j] = min dist from S to (i,j), and the move to (i,j) is horizontal
distV[i][j] = min dist from S to (i,j), and the move to (i,j) is vertical
horizontal => dir=1
vertical => dir=0
*/