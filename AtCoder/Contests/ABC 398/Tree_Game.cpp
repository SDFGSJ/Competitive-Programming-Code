#include<bits/stdc++.h>
using namespace std;
vector<int> T[105];
bool odd[105][105]; //odd[i][j] = true if dist from i to j is odd
void dfs(int u,int parent,int dist,int root){
    for(auto v:T[u]){
        if(v!=parent){
            if(dist%2 && dist!=1){
                odd[root][v]=true;
                odd[v][root]=true;
            }
            dfs(v,u,dist+1,root);
        }
    }
}
pair<int,int> findodd(int n){   //find a suitable pair (u,v) by brute force
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(odd[i][j]){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        T[u].emplace_back(v);
        T[v].emplace_back(u);
    }

    for(int i=1;i<=n;i++){
        dfs(i,-1,1,i);
    }

    int cnt=0;  //# of suitable ans
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(odd[i][j]){
                cnt++;
            }
        }
    }
    cnt/=2;

    if(cnt%2){  //we need to go first so we can win
        printf("First\n");
        fflush(stdout);
    }else{  //we go second so we need to read in takahashi's move
        printf("Second\n");
        fflush(stdout);
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==-1 && y==-1){ //there might be no suitable pairs at all
            return 0;
        }else{
            odd[x][y]=odd[y][x]=false;  //remove suitable pairs after adding edge
            cnt--;
        }
    }

    while(cnt){
        auto [u,v]=findodd(n);
        if(u!=-1 && v!=-1){
            printf("%d %d\n",u,v);
            fflush(stdout);
            odd[u][v]=odd[v][u]=false;
            cnt--;
        }
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==-1 && y==-1){
            return 0;
        }
        odd[x][y]=odd[y][x]=false;
        cnt--;
    }
    return 0;
}
/*
dfs + brute force
to prevent odd cycle, we need to find u,v, s.t. dist[u][v] is odd and add an edge between them
*/