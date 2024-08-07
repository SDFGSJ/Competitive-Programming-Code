#include<bits/stdc++.h>
using namespace std;
char grid[2010][2010];
int h,w;
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
bool ingrid(int r,int c){
    return 0<=r && r<h && 0<=c && c<w;
}
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int main(){
    DisjointSet ds(2010*2010);
    int q;
    scanf("%d%d%d",&h,&w,&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int r,c;
            scanf("%d%d",&r,&c);
            r--,c--;
            grid[r][c]='r';
            for(int i=0;i<4;i++){
                int nextr=r+dx[i];
                int nextc=c+dy[i];
                if(ingrid(nextr,nextc) && grid[nextr][nextc]=='r'){
                    ds.Union(r*w+c, nextr*w+nextc);
                }
            }
        }else{
            int ra,ca,rb,cb;
            scanf("%d%d%d%d",&ra,&ca,&rb,&cb);
            ra--,ca--,rb--,cb--;
            if(grid[ra][ca]=='r' && grid[rb][cb]=='r' && ds.Same(ra*w+ca, rb*w+cb)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
        }
    }
    return 0;
}