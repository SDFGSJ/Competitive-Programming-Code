#include<bits/stdc++.h>
using namespace std;
int a[55];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(i=0;i<2*n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+2*n);
        for(i=1;i<n;i+=2){
            swap(a[i],a[2*n-1-i]);
        }
        for(i=0;i<2*n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}