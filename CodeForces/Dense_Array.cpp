#include<bits/stdc++.h>
using namespace std;
int a[55];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++){
            int big=max(a[i],a[i+1]);
            int small=min(a[i],a[i+1]);
            if((double)big / small > 2.0){
                int tmp=small;
                while(tmp*2<big){
                    tmp*=2;
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}