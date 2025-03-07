#include<bits/stdc++.h>
using namespace std;
vector<int> pos[1000010];
int a[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        pos[a[i]].emplace_back(i);
    }

    int ans=INT_MAX;
    for(int i=1;i<=1000000;i++){
        if(pos[i].size()>=2){
            for(int j=0;j+1<pos[i].size();j++){
                ans=min(ans,pos[i][j+1]-pos[i][j]+1);
            }
        }
    }
    if(ans==INT_MAX){
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}
/*
maintain the list of idx where a number appears at
for a number num, the shortest subarray containing num can be derive by listing out all the idx s.t. a[idx]=num
and calc the min diff between 2 idxes
*/