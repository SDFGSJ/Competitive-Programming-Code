#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,vector<int>>> G;    //<cost,clique>
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
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int k;
        long long c;
        scanf("%d%lld",&k,&c);
        vector<int> clique;
        for(int j=0;j<k;j++){
            int u;
            scanf("%d",&u);
            clique.emplace_back(u);
        }
        G.emplace_back(c,clique);
    }
    sort(G.begin(),G.end());    //start from the clique with least cost edges

    DisjointSet ds(n);
    int edge_cnt=0;
    long long ans=0;
    for(auto [cost,cliq]:G){
        for(int i=1;i<cliq.size();i++){
            if(!ds.Same(cliq[0], cliq[i])){
                ds.Union(cliq[0], cliq[i]);
                ans+=cost;
                edge_cnt++;
            }
        }
    }
    if(edge_cnt==n-1){  //connected
        printf("%lld\n",ans);
    }else{
        printf("-1\n");
    }
    return 0;
}