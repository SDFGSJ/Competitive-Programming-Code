#include<bits/stdc++.h>
using namespace std;
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
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    DisjointSet ds(n);
    while(q--){
        int t,u,v;
        scanf("%d%d%d",&t,&u,&v);
        if(t==1){
            ds.Union(u,v);
        }else{
            if(ds.Same(u,v)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}