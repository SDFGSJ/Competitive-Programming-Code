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
pair<int,int> edges[200010];
deque<int> useless_edges;  //list of idx whose edge is useless
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    DisjointSet dsu(n);
    int compo=n;    //there are n components initially
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edges[i]={a,b};
        if(!dsu.Same(a,b)){ //a,b belongs to different compo
            compo--;
            dsu.Union(a,b);
        }else{  //a,b are already in the same compo, this edge is useless
            useless_edges.emplace_back(i);
        }
    }

    printf("%d\n",compo-1); //min # of edges to end up with 1 compo is "compo-1"
    int now=1;  //the current id of the vertex that is not connected to
    while(compo>1){
        int idx=useless_edges.front();
        auto [u,v]=edges[idx];
        if(!dsu.Same(u,now)){
            dsu.Union(u,now);
            compo--;
            printf("%d %d %d\n",idx,v,now); //before:u <-> v, after:u <-> now
            useless_edges.pop_front();
        }
        now++;
    }
    return 0;
}
/*
DSU
self loop and multi-edges are useless because they have no use in decreasing # of components
when reading in edges, build up the connected compo and maintain the # of component simultaneously
also keep track of the useless edges that can be used later
the min # of edges to be reconnected is obviously (# of compo)-1
so we start picking the useless edges (u,v) and try to connect u with the vertices that has not been connected yet(now)
that is, u is not connected to v anymore, whereas we connect u to now
repeat the process until there is only 1 compo left
*/