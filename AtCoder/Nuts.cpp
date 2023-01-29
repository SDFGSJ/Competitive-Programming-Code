#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
    int n,ans=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>10){
            ans+=a[i]-10;
        }
    }
    printf("%d\n",ans);
    return 0;
}