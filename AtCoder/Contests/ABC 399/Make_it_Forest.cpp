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
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    DisjointSet dsu(n);
    int ans=0;
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(!dsu.Same(u,v)){
            dsu.Union(u,v);
        }else{  //need to remove this edge in order to make it forest
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
dsu
*/