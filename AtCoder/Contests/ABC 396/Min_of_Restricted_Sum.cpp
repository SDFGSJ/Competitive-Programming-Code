#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> G[200010];    //<v,weight>
bool vis[200010];
int num[200010],bits[35];
vector<int> compo;
bool dfs(int u,int par,int sum){    //return false if there's a contradiction
    num[u]=sum;
    vis[u]=true;
    compo.emplace_back(u);
    for(auto [v,w]:G[u]){
        if(v!=par){
            if(!vis[v]){
                if(!dfs(v,u,sum^w)){
                    return false;
                }
            }else{
                if((num[u]^w)!=num[v]){
                    return false;
                }
            }
        }
    }
    return true;
}
void calc_bit_distri(int idx){
    //for every node in compo, calc num[node]'s bit distribution
    for(int i=0;i<32;i++){
        bits[i]=0;
    }
    for(auto node:compo){
        for(int i=0;i<32;i++){
            if(num[node]&(1<<i)){
                bits[i]++;
            }
        }
    }

    //if there are more 1's than 0's at the i-th bit, we should set the i-th bit of mask to 1 to have min xor sum
    int mask=0;
    for(int i=0;i<32;i++){
        int one_cnt=bits[i], zero_cnt=compo.size()-bits[i];
        if(one_cnt>=zero_cnt){
            mask|=(1<<i);
        }
    }

    for(auto node:compo){
        num[node]^=mask;
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            compo.clear();  //list of nodes that are in the same compo with i
            if(!dfs(i,-1,0)){
                printf("-1\n");
                return 0;
            }
            calc_bit_distri(i);
        }
    }

    for(int i=1;i<=n;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;
}
/*
transform the problem into an non-simple, weighted, undirected graph
view x,y as vertices, z as (x,y)'s edge weight
perform dfs on unvisited vertex with initial cost 0
if there is contradiction during dfs, the ans is -1
every compo is independent, and so is each bit of num[node] under xor operation

bits[i] = # of elements in num[] whose i-th bit is 1
Editorial, kotatsugame's video watched
*/