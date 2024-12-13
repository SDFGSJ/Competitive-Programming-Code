#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15];
vector<vector<int>> v;
void dfs(int idx,int num){
    a[idx]=num;
    if(idx==n){
        vector<int> tmp;
        for(int i=1;i<=n;i++){
            tmp.emplace_back(a[i]);
        }
        v.emplace_back(tmp);
        return;
    }

    for(int i=a[idx]+10;i<=m-10*(n-idx-1);i++){
        dfs(idx+1,i);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int num=1;num<=m-10*(n-1);num++){
        dfs(1,num);
    }
    printf("%ld\n",v.size());
    for(auto vec:v){
        for(auto num:vec){
            printf("%d ",num);
        }
        printf("\n");
    }
    return 0;
}
/*
brute force
*/