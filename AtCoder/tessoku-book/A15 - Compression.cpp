#include<bits/stdc++.h>
using namespace std;
int a[100010];
map<int,vector<int>> m; //<val,idx> may have duplicate value
set<int> s;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]].emplace_back(i);
        s.emplace(a[i]);
    }

    int rank=1;
    for(auto num:s){
        for(auto idx:m[num]){
            a[idx]=rank;
        }
        rank++;
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}