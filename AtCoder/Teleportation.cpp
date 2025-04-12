#include<bits/stdc++.h>
using namespace std;
int x[505],y[505];
set<pair<int,int>> ans;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==i){
                continue;
            }
            int dx=x[j]-x[i],dy=y[j]-y[i],k=__gcd(abs(dx),abs(dy));
            ans.emplace(dx/k,dy/k);
        }
    }
    printf("%ld\n",ans.size());
    return 0;
}
/*
enumerate every pair of (i,j), calc the vector from point i to point j
let this vector be (a,b), we can simplify it by calc a and b's gcd (a,b might be negative)
let k=gcd(|a|,|b|), then we store (a/k,b/k) to a set
*/