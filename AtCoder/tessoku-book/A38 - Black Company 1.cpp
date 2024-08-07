#include<bits/stdc++.h>
using namespace std;
int hours[10010];   //hours[i]=j => work j hours on day i
int main(){
    int d,n;
    scanf("%d%d",&d,&n);

    for(int i=1;i<=d;i++){  //init to max val
        hours[i]=24;
    }

    for(int i=0;i<n;i++){
        int l,r,h;
        scanf("%d%d%d",&l,&r,&h);
        for(int j=l;j<=r;j++){
            hours[j]=min(hours[j], h);
        }
    }

    int ans=0;
    for(int i=1;i<=d;i++){
        ans+=hours[i];
    }
    printf("%d\n",ans);
    return 0;
}