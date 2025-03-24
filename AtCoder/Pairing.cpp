#include<bits/stdc++.h>
using namespace std;
int cnt[5];
int main(){
    for(int i=1;i<=4;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    }

    int ans=0;
    for(int i=1;i<=4;i++){
        ans+=cnt[i]/2;
    }
    printf("%d\n",ans);
    return 0;
}