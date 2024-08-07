#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ans;
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    while(x!=1 || y!=1){
        ans.emplace_back(x,y);
        if(x>y){
            x-=y;
        }else{
            y-=x;
        }
    }

    printf("%ld\n",ans.size());
    for(int i=ans.size()-1;i>=0;i--){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}