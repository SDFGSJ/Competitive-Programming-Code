#include<bits/stdc++.h>
using namespace std;
int a[200010],pos[200010];  //pos[i] = number i's idx
vector<pair<int,int>> ans;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }

    for(int i=1;i<n;i++){
        if(a[i]!=i){
            int ipos=pos[i];
            swap(a[ipos],a[i]);
            pos[i]=i;
            pos[a[ipos]]=ipos;
            ans.emplace_back(i,ipos);
        }
    }
    printf("%d\n",ans.size());
    for(auto [f,s]:ans){
        printf("%d %d\n",f,s);
    }
    return 0;
}