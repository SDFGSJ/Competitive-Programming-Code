#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> s[200010];   //<color, cnt>
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        int color;
        scanf("%d",&color);
        s[i].emplace(color,1);
    }

    for(int i=0;i<q;i++){
        int source,target;
        scanf("%d%d",&source,&target);
        if(s[source].size()>s[target].size()){  //AC trick(try to move less balls)
            swap(s[source],s[target]);
        }
        for(auto item:s[source]){
            int color=item.first;
            auto iter=s[target].lower_bound(make_pair(color,0));
            if(iter!=s[target].end() && iter->first==color){
                int now=iter->second;
                s[target].erase(iter);
                s[target].emplace(color, now+1);
            }else{
                s[target].emplace(color,1);
            }
        }

        s[source].clear();
        printf("%d\n",s[target].size());
    }
    return 0;
}