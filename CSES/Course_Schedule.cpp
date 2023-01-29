#include<bits/stdc++.h>
using namespace std;
vector<int> g[100010];
int indegree[100010];
bool visited[100010];
int main(){
    int n,m,i;
    bool haveans=true;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].emplace_back(v);   //1-indexed
        indegree[v]++;
    }
 
    //a node will be pushed into todo <=> all its pre-tasks have been done(in-degree=0)
    vector<int> todo;
    for(i=1;i<=n;i++){
        if(!indegree[i]){
            todo.emplace_back(i);
        }
    }

    vector<int> order;  //the order of print out ans
    while(!todo.empty()){
        int now=todo.back();    //take arbitrary point
        todo.pop_back();

        visited[now]=true;
        order.emplace_back(now);

        for(auto neigh:g[now]){
            indegree[neigh]-=1;
            if(!indegree[neigh]){   //all pre-tasks done
                todo.emplace_back(neigh);
            }
        }
    }

    //if there exists a node that hasn't been visited, then it's not DAG
    for(i=1;i<=n;i++){
        if(!visited[i]){
            haveans=false;
            break;
        }
    }

    if(haveans){
        for(auto i:order){
            printf("%d ",i);
        }
    }else{
        printf("IMPOSSIBLE\n");
    }
    return 0;
}