#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    long long same=0,cnt=0;
    for(i=1;i<=n;i++){
        if(a[i]==i){
            same++;
        }else if(min(a[i], a[a[i]]) == i && max(a[i], a[a[i]]) == a[i]){
            cnt++;
        }
    }
    printf("%lld\n",cnt + same*(same-1)/2);
    return 0;
}