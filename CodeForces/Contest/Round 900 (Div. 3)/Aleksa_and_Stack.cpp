#include<bits/stdc++.h>
using namespace std;
int ans[200010];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        ans[0]=2,ans[1]=3;
        for(i=2;i<n;i++){
            ans[i]=ans[i-1]+1;
            while(((3*ans[i]) % (ans[i-2]+ans[i-1])) == 0){
                ans[i]++;
            }
        }
        
        for(i=0;i<n;i++){
            if(i==0){
                printf("%d",ans[i]);
            }else{
                printf(" %d",ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}