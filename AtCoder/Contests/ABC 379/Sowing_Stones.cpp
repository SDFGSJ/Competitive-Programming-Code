#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[200010];    //<idx,stone cnt>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&a[i].first);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&a[i].second);
    }
    sort(a,a+m);

    long long ans=0,r=n;    //r=n means start from the back
    int idx=m-1;
    while(idx>=0){
        auto [pos,stone]=a[idx];    //the closest pile of stone to r
        long long l=0;
        if(r-stone+1<pos){  //we can use stone stones to put 1 stone from idx r to r-stone+1
            //but that means pos will end up with >1 stones, which is invalid
            ans=-1;break;
        }else{
            l=r-stone+1;
        }
        ans+=(l+r)*(r-l+1)/2;
        ans-=1ll*pos*(r-l+1);
        r=l-1;  //move pointer
        idx--;  //proceed to the next pile of stone
    }
    if(r!=0){   //not able to place
        ans=-1;
    }
    printf("%lld\n",ans);
    return 0;
}