#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[300010];    //<end,start>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].second,&a[i].first);
    }
    sort(a,a+n);

    int cur_end=-1,ans=0;
    for(int i=0;i<n;i++){
        if(cur_end<=a[i].second){
            ans++;
            cur_end=a[i].first;
        }
    }
    printf("%d\n",ans);
    return 0;
}