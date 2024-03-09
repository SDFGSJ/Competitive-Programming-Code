#include<bits/stdc++.h>
using namespace std;
map<long long,long long> m;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int s,c;
        scanf("%d%d",&s,&c);
        m[s]=c;
    }

    long long ans=0;
    for(auto& [k,v]:m){
        m[2*k]+=v/2;
        if(v&1){
            ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}