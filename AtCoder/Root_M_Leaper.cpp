#include<bits/stdc++.h>
using namespace std;
int dist[405][405];
vector<pair<int,int>> dxy;
void add_dir_vec(int i,int j){  //if either i or j is 0, there will be duplicate pairs in dxy, but that's ok for bfs and dist[][] update
    dxy.emplace_back(i,j);
    dxy.emplace_back(i,-j);
    dxy.emplace_back(-i,j);
    dxy.emplace_back(-i,-j);
}
bool ingrid(int r,int c,int n){
    return 1<=r && r<=n && 1<=c && c<=n;
}
void bfs(int r,int c,int n){
    queue<pair<int,int>> q;
    q.emplace(1,1);
    dist[1][1]=0;
    while(!q.empty()){
        auto [r,c]=q.front();q.pop();
        for(auto [dx,dy]:dxy){
            int nextr=r+dx, nextc=c+dy;
            if(ingrid(nextr,nextc,n) && dist[nextr][nextc]==-1){
                dist[nextr][nextc]=dist[r][c]+1;
                q.emplace(nextr,nextc);
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    //init
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=-1;
        }
    }

    /*
    find i,j s.t. i^2+j^2=M
    although the upper bound for m is 1e6, the size of the grid is 400*400
    hence M is useless if M > 399*399 + 399*399, since the 1st step would be out of the grid
    brute force in [0,400] is enough
    */
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i*i+j*j==m){
                add_dir_vec(i,j);
            }
        }
    }

    bfs(1,1,n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
bfs
*/