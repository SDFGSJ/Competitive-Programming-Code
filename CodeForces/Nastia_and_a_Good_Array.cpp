#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int min_idx=min_element(a,a+n)-a;
        
        printf("%d\n",n-1);
        for(i=0;i<n;i++){
            if(i!=min_idx){
                printf("%d %d %d %d\n",min_idx+1,i+1,a[min_idx],a[min_idx]+abs(i-min_idx));
            }
        }
    }
    return 0;
}