#include<bits/stdc++.h>
using namespace std;
int x[200010],xsort[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
        xsort[i]=x[i];
    }
    sort(xsort+1,xsort+1+n);

    for(int i=1;i<=n;i++){
        int ans=0;
        if(x[i]<=xsort[(n+1)/2]){
            ans=xsort[(n+1)/2 + 1];
        }else{
            ans=xsort[(n+1)/2];
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
copy x[] into xsort[] and sort xsort[] in asc
suppose xsort[] has 2n elements, then the ans must be either xsort[n] or xsort[n+1] (1-indexed), since we only remove 1 number
if the number we remove <= xsort[n]
=> the number we remove is in the 1st half xsort[1..n], so the 1st half now contains n-1 elements, 2nd half contains n elements
=> the 1st element in the 2nd half = xsort[n+1] is the median
same logic when the number we remove > xsort[n]
*/