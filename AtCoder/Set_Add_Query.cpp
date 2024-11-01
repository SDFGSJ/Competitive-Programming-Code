#include<bits/stdc++.h>
using namespace std;
vector<int> pos[200010];
unordered_set<int> us;
long long pre[200010],ans[200010];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++){
        int x;
        scanf("%d",&x);
        pos[x].emplace_back(i);   //1-indexed
        if(us.count(x)){
            us.erase(x);
        }else{
            us.emplace(x);
        }
        pre[i]=(long long)us.size();
    }

    for(int i=1;i<=q;i++){
        pre[i]+=pre[i-1];
    }

    for(int i=1;i<=n;i++){
        pos[i].emplace_back(q+1);
        for(int j=1;j<pos[i].size();j+=2){
            int lidx=pos[i][j-1], ridx=pos[i][j];   //want to find sum in range[lidx, ridx-1]
            ans[i]+=pre[ridx-1]-pre[lidx-1];
        }
        printf("%lld ",ans[i]);
    }
    printf("\n");
    return 0;
}
/*
let pre[i] = # of distinct elements in set S as of idx i, and cal prefix sum
pos[i] = list of idxs that number i appears at, append q+1 to the end
ex.
1 3 3 2
pos[1]={1,q+1} => +=pre[q+1-1]-pre[1-1]
pos[2]={4,q+1} => +=pre[q+1-1]-pre[4-1]
pos[3]={2,3,q+1} => pre[3-1]-pre[2-1]
*/