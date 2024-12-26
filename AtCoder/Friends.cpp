#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
public:
    vector<int> parent;
    int find_root(int x) {
        if (x == parent[x]) return x;
        int root = find_root(parent[x]);
        return parent[x] = root; // ¸ô®|À£ÁY
    }
    DisjointSet(size_t n) : parent(n + 1) { init(); }
    void init() {
        for (size_t i = 0; i < parent.size(); ++i)
            parent[i] = i;
    }
    bool Same(int a, int b) { return find_root(a) == find_root(b); }
    void Union(int a, int b) { parent[find_root(a)] = find_root(b); }
};
int sz[200010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    DisjointSet dsu(n);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(!dsu.Same(a,b)){
            dsu.Union(a,b);
        }
    }

    for(int i=1;i<=n;i++){
        int root=dsu.find_root(i);
        sz[root]++;
    }

    int ans=1;
    for(int i=1;i<=n;i++){
        ans=max(ans,sz[i]);
    }
    printf("%d\n",ans);
    return 0;
}
/*
dsu
sz[i] = # of people who are under the group led by person i
ans = the max size of all components
suppose the size of the max group is k
we create k groups and put everyone in the max group into k different groups
so that no one would know each other
*/