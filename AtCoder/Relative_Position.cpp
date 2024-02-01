#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> G[200010];   //<b,dx,dy>
bool visited[200010];
queue<tuple<int,long long,long long>> q;
pair<long long,long long> coor[200010]; //coordinate
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,x,y;
        scanf("%d%d%d%d",&a,&b,&x,&y);
        G[a].emplace_back(b,x,y);
        G[b].emplace_back(a,-x,-y);
    }

    //bfs starting from 1
    q.emplace(1,0,0);
    visited[1]=true;
    coor[1]={0,0};
    while(!q.empty()){
        int a;
        long long ax,ay;
        tie(a,ax,ay)=q.front();q.pop();
        for(auto [b,dx,dy]:G[a]){
            if(!visited[b]){
                visited[b]=true;
                coor[b]={ax+dx,ay+dy};
                q.emplace(b,ax+dx,ay+dy);
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(visited[i]){ //same component with 1
            printf("%lld %lld\n",coor[i].first,coor[i].second);
        }else{
            printf("undecidable\n");
        }
    }
    return 0;
}