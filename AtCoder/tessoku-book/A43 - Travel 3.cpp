#include<bits/stdc++.h>
using namespace std;
vector<int> east,west;
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=0;i<n;i++){
        int a;char b;
        scanf("%d %c",&a,&b);
        if(b=='E'){
            east.emplace_back(a);
        }else{
            west.emplace_back(a);
        }
    }

    int ans=0;
    for(auto pos:east){
        ans=max(ans,l-pos);
    }
    for(auto pos:west){
        ans=max(ans,pos);
    }
    printf("%d\n",ans);
    return 0;
}