#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> parent;
    int find_root(int x) {
        if (x == parent[x]) return x;
        int root = find_root(parent[x]);
        return parent[x] = root;
    }
public:
    DisjointSet(size_t n) : parent(n + 1) { init(); }
    void init() {
        for (size_t i = 0; i < parent.size(); ++i)
            parent[i] = i;
    }
    bool Same(int a, int b) { return find_root(a) == find_root(b); }
    void Union(int a, int b) { parent[find_root(a)] = find_root(b); }
};
vector<tuple<int,int,int>> E;   //<cost,u,v>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        E.emplace_back(c,a,b);
    }

    sort(E.begin(),E.end());
    DisjointSet dsu(n);
    long long ans=0;
    for(auto [cost,u,v]:E){
        if(dsu.Same(u,v)){
            if(cost>0){
                ans+=cost;
            }
        }else{
            dsu.Union(u,v);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
DSU + MST-like greedy
sort the edges (cost,u,v) asc and start picking edges from the smallest cost
if u,v are connected
    if cost>0, we can always get positive reward by removing this edge, so we add this cost to the ans
    else: the cost would decrease our reward, dont add this cost
else
    connect u,v
*/