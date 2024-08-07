#include<bits/stdc++.h>
using namespace std;
int a[300010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int q;
    scanf("%d",&q);
    while(q--){
        int b,ans=0;
        scanf("%d",&b);
        int idx=lower_bound(a,a+n,b)-a;
        if(idx==0){
            ans=a[idx]-b;
        }else if(idx==n){
            ans=b-a[idx-1];
        }else{
            ans=min(abs(a[idx]-b), abs(a[idx-1]-b));
        }
        printf("%d\n",ans);
    }
    return 0;
}