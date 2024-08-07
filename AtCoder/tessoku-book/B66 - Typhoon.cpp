#include<bits/stdc++.h>
using namespace std;
pair<int,int> edges[100010];
tuple<int,int,int> query[100010];   //<op type=1, x, 0> or <op type=2, u, v>
bool unavail[100010];   //unavail[i] = true if edges[i] is unavailable
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
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edges[i]={a,b};
    }

    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            query[i]={1,x,0};
            unavail[x]=true;
        }else{
            int u,v;
            scanf("%d%d",&u,&v);
            query[i]={2,u,v};
        }
    }

    //build the final graph when all queries are done
    DisjointSet ds(n);
    for(int i=1;i<=m;i++){
        if(!unavail[i]){
            ds.Union(edges[i].first, edges[i].second);
        }
    }

    vector<string> ans;
    for(int i=q-1;i>=0;i--){    //execute the queries in reverse
        int type=get<0>(query[i]);
        if(type==1){
            int idx=get<1>(query[i]);
            ds.Union(edges[idx].first, edges[idx].second);  //add this edge back to graph
        }else{
            int u,v;
            tie(ignore,u,v)=query[i];
            if(ds.Same(u,v)){
                ans.emplace_back("Yes");
            }else{
                ans.emplace_back("No");
            }
        }
    }

    for(int i=ans.size()-1;i>=0;i--){
        printf("%s\n",ans[i].c_str());
    }
    return 0;
}