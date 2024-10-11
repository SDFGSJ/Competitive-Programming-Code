#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<int> pos[200010];
int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=200000;i++){
        pos[i].emplace_back(0); //convenient for calculation
    }

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pos[a[i]].emplace_back(i);
    }

    for(int i=1;i<=200000;i++){
        pos[i].emplace_back(n+1);   //convenient for calculation
    }

    long long ans=0;
    for(int i=1;i<=200000;i++){
        if(pos[i].size()==2){   //i is not in a[]
            continue;
        }
        ans+=1ll*n*(n+1)/2;
        for(int j=0;j+1<pos[i].size();j++){
            long long num=pos[i][j+1]-pos[i][j]-1;  //# of i's between 2 index
            ans-=(num*(num+1)/2);   //# of subarrays that does not contain i
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
https://atcoder.jp/contests/abc371/editorial/10933
*/