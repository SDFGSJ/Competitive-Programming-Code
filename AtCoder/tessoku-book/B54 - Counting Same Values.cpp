#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        m[num]++;
    }

    long long ans=0;
    for(auto [k,v]:m){
        ans+=1ll*v*(v-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}