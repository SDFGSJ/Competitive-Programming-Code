#include<bits/stdc++.h>
using namespace std;
map<int,int> m; //<color,min>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,c;
        scanf("%d%d",&a,&c);
        if(m[c]==0){
            m[c]=a;
        }else{
            m[c]=min(m[c],a);
        }
    }
    int ans=-1;
    for(auto [k,v]:m){
        ans=max(ans,v);
    }
    printf("%d\n",ans);
    return 0;
}