#include<bits/stdc++.h>
using namespace std;
int a[200010],l[200010],r[200010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        l[i]=r[i]=a[i];
    }

    l[0]=1;
    for(int i=1;i<n;i++){
        l[i]=min(a[i],l[i-1]+1);
    }

    r[n-1]=1;
    for(int i=n-2;i>=0;i--){
        r[i]=min(a[i],r[i+1]+1);
    }

    int ans=-1;
    for(int i=0;i<n;i++){
        l[i]=min(l[i],r[i]);
        ans=max(ans,l[i]);
    }
    printf("%d\n",ans);
    return 0;
}
/*
l[i] = max height of pos i when constructing from the left
r[i] = max height of pos i when constructing from the right
*/