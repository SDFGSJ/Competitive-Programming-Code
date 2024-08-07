#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    sort(b,b+n);

    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b[i]);
    }
    printf("%lld\n",ans);
    return 0;
}