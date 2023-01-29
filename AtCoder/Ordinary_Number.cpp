#include<bits/stdc++.h>
using namespace std;
int a[25];
int main(){
    int n,ans=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i+1<n;i++){
        int m=min({a[i-1],a[i],a[i+1]});
        int M=max({a[i-1],a[i],a[i+1]});
        if(m<a[i] && a[i]<M){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}