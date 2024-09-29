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
set<int,greater<>> compo[200010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++){
        compo[i].emplace(i);
    }

    DisjointSet dsu(n);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int u,v;
            scanf("%d%d",&u,&v);
            if(!dsu.Same(u,v)){
                int uroot=dsu.find_root(u), vroot=dsu.find_root(v);
                if(compo[uroot].size()>compo[vroot].size()){
                    swap(compo[uroot],compo[vroot]);
                }
                for(auto node:compo[uroot]){    //move nodes in u to v
                    compo[vroot].emplace(node);
                }
                compo[uroot].clear();
                dsu.Union(u,v);
            }
        }else{
            int v,k;
            scanf("%d%d",&v,&k);
            int vroot=dsu.find_root(v);
            if(compo[vroot].size()<k){
                printf("-1\n");
            }else{
                int cnt=1;
                for(auto it=compo[vroot].begin();cnt<=k;it++, cnt++){
                    if(cnt==k){
                        printf("%d\n",*it);
                    }
                }
            }
        }
    }
    return 0;
}
/*
compo[i] = list of nodes that is under node i
*/