#include<bits/stdc++.h>
using namespace std;
int a[200010],prefix[200010];
int main(){
    int n,q,i;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    prefix[0]=a[0];
    for(i=1;i<n;i++){
        prefix[i]=prefix[i-1]^a[i];
    }

    for(i=0;i<q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        printf("%d\n",prefix[b]^prefix[a-1]);
    }
    return 0;
}