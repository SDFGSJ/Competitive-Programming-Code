#include<bits/stdc++.h>
using namespace std;
int a[105];
int appear[101];    //did i-th show appears?
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        //n days,k shows,d consecutive days
        int n,k,d,ans=1000,cnt;
        scanf("%d%d%d",&n,&k,&d);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0;i+d<=n;i++){
            cnt=0;
            for(j=0;j<101;j++){
                appear[j]=0;
            }
            for(j=0;j<d;j++){
                if(appear[a[i+j]]==0){
                    appear[a[i+j]]=1;
                    cnt++;
                }
            }
            if(cnt<ans){
                ans=cnt;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}