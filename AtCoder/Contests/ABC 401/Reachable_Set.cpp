#include<bits/stdc++.h>
using namespace std;
vector<int> G[200010];
unordered_set<int> to_be_remove;    //set of nodes to be removed after adding node i to graph
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
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i=1;i<=n;i++){
        sort(G[i].begin(),G[i].end());
    }

    DisjointSet dsu(n);
    int compo=0;    //# of component in current graph
    for(int i=1;i<=n;i++){
        compo++;
        if(to_be_remove.find(i)!=to_be_remove.end()){   //node i is going to be added, remove node i from set
            to_be_remove.erase(i);
        }
        for(auto neigh:G[i]){
            if(neigh<=i-1){
                if(!dsu.Same(i,neigh)){  //if node i does not belong to the neigh's compo, then # of compo decrease by 1
                    compo--;
                }
                dsu.Union(i,neigh);
            }else{  //nodes that are >= i should be removed to make the set of reachable nodes = {1,2...i}
                to_be_remove.emplace(neigh);
            }
        }
        int ans=0;
        if(compo==1){   //if there is only 1 compo after adding node i, it means that 1,2...i are reachable to each other
            ans=to_be_remove.size();
        }else{  //if there are >=2 compo after adding node i, it means that it's impossible to reach node i by traversing edges
            ans=-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
dsu
we add nodes to the graph 1 by 1 and start adding from node 1
when adding node i, we only care about whether node i connects to node j (1<=j<=i-1), so we sort adj list in asc
Editorial video watched
*/