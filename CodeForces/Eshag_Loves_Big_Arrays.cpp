#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,sum=0,cnt=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        for(i=1;i<=n;i++){
            sum+=a[i];
            if(a[i] <= sum/i){
                cnt++;
            }
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}