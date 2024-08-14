#include<bits/stdc++.h>
using namespace std;
int a[200010];
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
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    DisjointSet ds(200010);

    int ans=0;
    for(int i=0;i<n/2;i++){
        if(!ds.Same(a[i], a[n-1-i])){
            ds.Union(a[i], a[n-1-i]);   //change a[n-1-i] to a[i]
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}