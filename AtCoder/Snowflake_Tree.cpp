#include<bits/stdc++.h>
using namespace std;
vector<int> T[300010];
int deg[300010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        T[u].emplace_back(v);
        T[v].emplace_back(u);
        deg[u]++,deg[v]++;
    }

    int ans=n;
    for(int root=1;root<=n;root++){ //enumerate every node as root
        vector<int> d;  //the degree of root's neighbors
        for(auto x:T[root]){
            d.emplace_back(deg[x]-1);   //# of lv2 node, doesn't count root inside, so -1
        }
        sort(d.rbegin(),d.rend());  //pick from the largest <= didn't come up with this at first
        for(int i=0;i<d.size();i++){
            ans=min(ans,n-(1 + (i+1) + (i+1)*d[i]));    //# of node in snowflake tree = root + (# of lv1 node x) + (# of lv2 node y)
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
degree
Editorial video watched
finish "read task => my code => editorial => others' code"
*/