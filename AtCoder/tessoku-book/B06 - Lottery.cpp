#include<bits/stdc++.h>
using namespace std;
int a[100010],pre[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==0){
            a[i]=-1;
        }
    }

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int result=pre[r]-pre[l-1];
        if(result<0){
            printf("lose\n");
        }else if(result>0){
            printf("win\n");
        }else{
            printf("draw\n");
        }
    }
    return 0;
}