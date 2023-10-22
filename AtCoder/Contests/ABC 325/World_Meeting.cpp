#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;    //<employee, clock>
int main(){
    int n;
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&v[i].first,&v[i].second);
    }
    int ans=0;
    for(int i=0;i<24;i++){
        int people=0;
        for(int j=0;j<n;j++){
            int hour=(v[j].second+i)%24;
            if(9<=hour && hour<=17){
                people+=v[j].first;
            }
        }
        ans=max(ans,people);
    }
    printf("%d\n",ans);
    /*for(auto [a,b]:v){
        printf("%d %d\n",a,b);
    }*/
    return 0;
}