#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans+=lower_bound(a+j+1,a+n,a[i]+a[j])-upper_bound(a+j+1,a+n,a[j]-a[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
sort + enumerate
O(N^2) for loop enumerate a=arr[i] and b=arr[j] (a<b)
find
# of c s.t. max(a-b,b-a) < c < a+b
= # of c in (b-a, a+b)
= lower_bound(a+b) - upper_bound(b-a)

beware of searching range to avoid calculate the same tuple multiple times
*/