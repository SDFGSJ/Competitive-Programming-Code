#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int> a[100010];   //<prefecture,year,input idx>
int idxs[100010];
pair<int,int> ans[100010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int p,y;
        scanf("%d%d",&p,&y);
        a[i]=make_tuple(p,y,i);
    }

    sort(a,a+m);
    for(int i=0;i<m;i++){
        int p,y,idx;
        tie(p,y,idx)=a[i];

        ans[idx]=make_pair(p,idxs[p]);
        idxs[p]++;
    }
    for(int i=0;i<m;i++){
        printf("%06d%06d\n",ans[i].first,ans[i].second+1);
    }
    return 0;
}