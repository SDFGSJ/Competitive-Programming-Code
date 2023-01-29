#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,Min=1e9,minidx=-1;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=0;i<n-1;i++){
            if(a[i+1]-a[i]<Min){
                Min=a[i+1]-a[i];
                minidx=i;
            }
        }
        printf("%d ",a[minidx]);
        for(i=minidx+2;i<n;i++){
            printf("%d ",a[i]);
        }
        for(i=0;i<minidx;i++){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[minidx+1]);
    }
    return 0;
}