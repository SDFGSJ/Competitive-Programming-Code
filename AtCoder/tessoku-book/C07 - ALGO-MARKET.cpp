#include<bits/stdc++.h>
using namespace std;
int c[100010],pre[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    sort(c+1,c+1+n);

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+c[i];
    }

    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        int idx=lower_bound(pre+1,pre+1+n,x)-pre;
        if(pre[idx]>x || idx>n){
            idx--;
        }
        printf("%d\n",idx);
    }
    return 0;
}