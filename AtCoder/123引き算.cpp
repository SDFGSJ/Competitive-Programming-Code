#include<bits/stdc++.h>
using namespace std;
bool vis[305];
bool bfs(int start,int ng1,int ng2,int ng3){
    queue<pair<int,int>> q; //<num,step>
    q.emplace(start,0);
    while(!q.empty()){
        auto [num,step]=q.front();q.pop();
        if(num==ng1 || num==ng2 || num==ng3){   //num is 1 of the 3 ng's, dont expand further
            continue;
        }
        if(num==0 && step<=100){    //reach the goal
            return true;
        }
        if(vis[num] || step>=100){  //can only do 100 times
            continue;
        }
        vis[num]=true;
        for(int i=1;i<=3;i++){
            q.emplace(num-i,step+1);
        }
    }
    return false;
}
int main(){
    int n,ng1,ng2,ng3;
    scanf("%d%d%d%d",&n,&ng1,&ng2,&ng3);
    if(bfs(n,ng1,ng2,ng3)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
/*
bfs
*/