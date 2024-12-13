#include<bits/stdc++.h>
using namespace std;
char s[15];
map<array<int,26>,int> m;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        array<int,26> arr={0};
        for(int j=0;j<10;j++){
            arr[s[j]-'a']++;
        }
        m[arr]++;
    }

    long long ans=0;
    for(auto [k,v]:m){
        ans+=1ll*v*(v-1)/2;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
calculate the alphabet distribution of every string
use a map to maintain the # of string that has the same distribution
the final ans would be sum(v(v-1)/2) for every [_,v] in map
*/