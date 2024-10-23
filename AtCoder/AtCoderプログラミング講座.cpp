#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);

    double ans=0.0;
    for(int i=n-k;i<n;i++){
        ans=(ans+a[i])/2.0;
    }
    printf("%.10f\n",ans);
    return 0;
}