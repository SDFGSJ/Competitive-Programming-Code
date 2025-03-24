#include<bits/stdc++.h>
using namespace std;
int a[300010];
unordered_map<int,int> l,r; //<num,cnt>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        r[a[i]]++;
    }

    int ans=-1;
    for(int i=1;i<=n-1;i++){
        l[a[i]]++,r[a[i]]--;
        if(r[a[i]]==0){
            r.erase(a[i]);
        }
        ans=max(ans,(int)(l.size()+r.size()));
    }
    printf("%d\n",ans);
    return 0;
}
/*
unordered map
we use 2 unordered map to maintain the number distribution of 2 subarrays
r maintains the counter of a[] initially, then we enumerate each i from 1 to n-1
when focusing on i, we add a[i] to l[], remove a[i] from r[]
if r[] does not contain a[i] anymore, erase key a[i] from r[]
then the sum of the counts of distinct integers in those subarrays = l.size()+r.size()
*/