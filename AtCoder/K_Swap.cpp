#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<int> group[200010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        group[i%k].emplace_back(a[i]);
    }

    for(int i=0;i<k;i++){
        sort(group[i].begin(),group[i].end());
    }

    vector<int> res;
    for(int i=0;i<n;i++){
        res.emplace_back(group[i%k][i/k]);
    }

    bool asc=true;
    for(int i=0;i+1<n;i++){
        if(res[i]>res[i+1]){
            asc=false;
        }
    }

    if(asc){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
observation
since we can only swap a[i] and a[i+k], so a[i] can swap with a[i+k],a[i+2k]...
=> a[i] can swap with a[idx] as long as idx%k == i%k
divide a[] into k groups and sort them respectively
get a sorted array by merging these k groups
when merging, group idx = i%k and the element idx = i/k
*/