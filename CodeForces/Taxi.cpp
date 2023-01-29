#include<bits/stdc++.h>
using namespace std;
int cnt[5];
int main(){
    int n,num,i,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        cnt[num]++;
    }
    ans+=cnt[4];
    cnt[4]=0;

    ans+=cnt[2]/2;
    cnt[2]-=2*(cnt[2]/2);
    
    int tmp=min(cnt[1],cnt[3]);
    ans+=tmp;
    cnt[1]-=tmp;
    cnt[3]-=tmp;

    if(cnt[1]!=0){
        ans+=(int)ceil( (cnt[1]+2*cnt[2])/4.0 );    //cnt[2] remember to * 2
    }else{
        ans+=(cnt[3]+cnt[2]);
    }

    cnt[1]=cnt[2]=cnt[3]=0;

    printf("%d\n",ans);
    return 0;
}