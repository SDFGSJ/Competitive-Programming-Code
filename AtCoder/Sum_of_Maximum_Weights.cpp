#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> parent;
public:
    int find_root(int x) {
        if (x == parent[x]) return x;
        int root = find_root(parent[x]);
        return parent[x] = root;
    }
    DisjointSet(size_t n) : parent(n + 1) { init(); }
    void init() {
        for (size_t i = 0; i < parent.size(); ++i)
            parent[i] = i;
    }
    bool Same(int a, int b) { return find_root(a) == find_root(b); }
    void Union(int a, int b) { parent[find_root(a)] = find_root(b); }
};
tuple<int,int,int> edges[100010];   //<weight,u,v>
int sz[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges[i]=make_tuple(w,u,v);
    }

    sort(edges,edges+n-1);
    for(int i=1;i<=n;i++){
        sz[i]=1;
    }

    DisjointSet dsu(n);
    long long ans=0;
    for(int i=0;i<n-1;i++){
        int w,u,v;
        tie(w,u,v)=edges[i];
        int u_subtree_sz=sz[dsu.find_root(u)], v_subtree_sz=sz[dsu.find_root(v)];
        ans+=1ll*w*u_subtree_sz*v_subtree_sz;
        sz[dsu.find_root(u)]+=v_subtree_sz;
        sz[dsu.find_root(v)]+=u_subtree_sz;
        dsu.Union(u,v);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
DSU
sort edge weight asc
every node does not have edge initially, construct the original graph by picking the smallest weight edge
by doing so, we can guaranteed that this weight is the maxmimum among all pairs of nodes that pass thru this edge until now
find the size of the subtree rooted at u and v respectively
and this weight will contribute w*(u's subtree size)*(v's subtree size) to the ans
since every node in u's subtree go thru this edge to reach every node in v's subtree
then merge u,v to become the same component
*/