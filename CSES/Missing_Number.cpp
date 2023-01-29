#include<bits/stdc++.h>
using namespace std;
int a[200010],exist[200010];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d",&a[i]);
        exist[a[i]]=1;
    }
    for(i=1;i<=n;i++){
        if(!exist[i]){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}