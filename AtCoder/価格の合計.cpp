#include<bits/stdc++.h>
using namespace std;
int a[25];
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        if(x&(1<<i)){
            ans+=a[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
simple bitwise operation
*/