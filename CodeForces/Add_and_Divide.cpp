#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int a,b,tmp,cnt,ans=1e9;
        scanf("%d%d",&a,&b);
        /*
        if b==1,then we have to start from 2
        only have to brute force until b+ans,which means b++ ans times
        */
        for(i=max(b,2);i<=b+ans;i++){
            cnt=0;
            tmp=a;
            cnt+=i-b;   //remember to add the difference
            while(tmp!=0){
                tmp/=i;
                cnt++;
            }
            if(cnt<ans){
                ans=cnt;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}