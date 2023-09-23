#include<bits/stdc++.h>
using namespace std;
int a[15],mymin=100;
int main(){
    int t,n,ans,i;
    scanf("%d",&t);
    while(t--){
        ans=1,mymin=100;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            mymin=min(mymin,a[i]);
        }
        for(i=0;i<n;i++){
            if(a[i]==mymin){
                a[i]++;
                break;
            }
        }
        for(i=0;i<n;i++){
            //printf("(%d) ",a[i]);
            ans*=a[i];
        }

        printf("%d\n",ans);
    }
    return 0;
}