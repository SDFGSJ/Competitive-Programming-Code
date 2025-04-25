#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int color[1005][1005];  //color[i][j] = the id of the compo which (i,j) belongs to, =0 if (i,j) is red
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int h,w;
const int mod=998244353;
long long mypow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}
void bfs(int sr,int sc,int c){
    queue<pair<int,int>> q;
    q.emplace(sr,sc);
    color[sr][sc]=c;
    while(!q.empty()){
        auto [row,col]=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nr=row+dx[i],nc=col+dy[i];
            if(ingrid(nr,nc) && grid[nr][nc]=='#' && !color[nr][nc]){
                q.emplace(nr,nc);
                color[nr][nc]=c;
            }
        }
    }
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++){
        scanf("%s",grid[i]+1);
    }

    int c=1;    //give each green compo an id
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='#' && !color[i][j]){
                bfs(i,j,c);
                c++;
            }
        }
    }
    //total # of compo = c-1

    long long redcnt=0,nomina=0; //nominator
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='.'){
                redcnt++;
                unordered_set<int> compo;
                for(int k=0;k<4;k++){
                    int ni=i+dx[k],nj=j+dy[k];
                    if(ingrid(ni,nj) && color[ni][nj]){
                        compo.emplace(color[ni][nj]);
                    }
                }
                nomina+=(c-1)-compo.size()+1;
                nomina%=mod;    //beware of overflow since nomina can reach 25*(10^10)
            }
        }
    }
    printf("%lld\n",nomina*mypow(redcnt,mod-2)%mod);
    return 0;
}
/*
bfs
use bfs to count the # of green compo
in order to get the # of green compo after repainting (i,j) from red to green,
we need to know the # of different green compo next to (i,j), let this number be C
then the # of green compo after repainting = (total # of green compo) - C + 1
since we lost the original C green compos by repainting (i,j),
but we get a larger green compo after merging them together
*/