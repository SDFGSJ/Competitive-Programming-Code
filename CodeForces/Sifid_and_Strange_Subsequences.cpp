#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,cnt=1,Min=1e9;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=1;i<n;i++){
            if(a[i]-a[i-1]<Min){
                Min=a[i]-a[i-1];
            }
            if(Min>=a[i]){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}