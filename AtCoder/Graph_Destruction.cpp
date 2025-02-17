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
vector<int> G[200010];
int ans[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].emplace_back(b);   //constraints guarantee that a<b
    }

    DisjointSet dsu(n);
    int compo=0;
    for(int i=n;i>=2;i--){
        ans[i]=compo;
        for(auto v:G[i]){
            if(!dsu.Same(i,v)){ //add edges, if not the same compo, compo minus 1
                dsu.Union(i,v);
                compo--;
            }
        }
        compo++;    //add node i back
    }
    ans[1]=compo;
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
/*
dsu + do in reverse order
compo=0 after performing all n operations
when adding edges going out from u, only add those (u,v) where u<v
so we sort the adj list and maintain the pointer to the node to be added for each list
instead of scanning through all u's neighbors when adding u back
*/