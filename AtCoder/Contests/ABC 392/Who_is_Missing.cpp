#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool exist[1010];
vector<int> ans;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
        exist[a[i]]=true;
    }

    for(int i=1;i<=n;i++){
        if(!exist[i]){
            ans.emplace_back(i);
        }
    }

    printf("%ld\n",ans.size());
    for(auto num:ans){
        printf("%d ",num);
    }
    printf("\n");
    return 0;
}