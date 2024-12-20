#include<bits/stdc++.h>
using namespace std;
long long grid[505][505];
bool absorbed[505][505];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int h,w;

struct cmp{
    bool operator() (const pair<int,int>& p1,const pair<int,int>& p2 ){
        auto [r1,c1]=p1;
        auto [r2,c2]=p2;
        return grid[r1][c1]>grid[r2][c2];
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

bool ingrid(int r,int c){
    return 1<=r && r<=h && 1<=c && c<=w;
}

int main(){
    int x,p,q;
    scanf("%d%d%d%d%d",&h,&w,&x,&p,&q);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf("%lld",&grid[i][j]);
        }
    }

    long long ans=0;
    pq.emplace(p,q);
    while(!pq.empty()){
        auto [r,c]=pq.top();pq.pop();

        //special case to filter out (p,q)
        //if we can't merge with the min element, the process should stop
        if((r!=p || c!=q) && (ans+x-1) / x <= grid[r][c]){
            break;
        }
        if(absorbed[r][c] || !ingrid(r,c)){
            continue;
        }
        absorbed[r][c]=true;
        ans+=grid[r][c];
        for(int i=0;i<4;i++){
            pq.emplace(r+dx[i],c+dy[i]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
strength/x > grid[r][c]
=> ceil(strength/x) > grid[r][c]
=> floor((strength+x-1) / x) > grid[r][c]
*/