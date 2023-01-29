#include<bits/stdc++.h>
using namespace std;
set<int> v[100010]; //adjacency list
vector<int> ans;
bool visited[100010];
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);    //1-indexed
        v[a].insert(b);
        v[b].insert(a);
    }
    
    visited[1]=true;
    pq.push(1);
    while(!pq.empty()){
        int now=pq.top();
        ans.push_back(now);
        pq.pop();
        for(auto num:v[now]){
            if(!visited[num]){
                visited[num]=true;
                pq.push(num);
            }
        }
    }
    
    for(auto i:ans){
        printf("%d ",i);
    }
    printf("\n");
    return 0;
}
