#include<bits/stdc++.h>
using namespace std;
int a[105],ans[105];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if(a[0]==1){
            ans[0]=2;
        }else{
            ans[0]=1;
        }
        for(i=1;i<n;i++){
            ans[i]=ans[i-1]+1;
            while(ans[i]==a[i]){
                ans[i]++;
            }
        }
        printf("%d\n",ans[n-1]);
    }
    return 0;
}