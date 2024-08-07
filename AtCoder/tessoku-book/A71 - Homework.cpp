#include<bits/stdc++.h>
using namespace std;
int a[65],b[65];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+n,greater<int>());

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i]*b[i];
    }
    printf("%d\n",ans);
    return 0;
}