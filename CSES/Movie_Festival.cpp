#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[200010];    //<end,start>
int main(){
    int n,cur_end=-1,ans=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){   //input gives <start,end>,we read in <end,start> in order to sort
        scanf("%d %d",&a[i].second,&a[i].first);
    }

    sort(a,a+n);
    for(i=0;i<n;i++){
        if(cur_end<=a[i].second){   //if the current event ends before the next event start, then we can join
            ans++;
            cur_end=a[i].first;
        }
    }
    printf("%d\n",ans);
    return 0;
}