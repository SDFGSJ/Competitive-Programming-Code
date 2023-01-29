#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,m=1e9,cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]<m){
                m=a[i];
            }
        }
        for(i=0;i<n;i++){
            if(a[i]!=m){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}