#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u,v,cost;
    bool operator<(const Edge& other){
        return cost<other.cost;
    }
};
class DisjointSet {
    vector<int> parent;
    int find_root(int x) {
        if (x == parent[x]) return x;
        int root = find_root(parent[x]);
        return parent[x] = root; // ¸ô®|À£ÁY
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
vector<Edge> edges;
int MST(int n){
    sort(edges.begin(),edges.end());
    DisjointSet ds(n);
    int ans=0;
    for(auto e:edges){
        if(ds.Same(e.u,e.v)){
            continue;
        }
        ds.Union(e.u,e.v);
        ans+=e.cost;
    }
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    edges.resize(m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].cost);
    }
    printf("%d\n",MST(n));
    return 0;
}