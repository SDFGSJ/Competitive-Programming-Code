#include<bits/stdc++.h>
using namespace std;
int a[200010],pos[200010];    //pos[i]=number i's idx (1-indexed)
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        a[i]=pos[i]=i;
    }
    for(int i=0;i<q;i++){
        int x;
        scanf("%d",&x);
        if(pos[x]==n){  //rightmost
            swap(pos[a[n]],pos[a[n-1]]);
            swap(a[n],a[n-1]);
        }else{
            int now_idx=pos[x], right_idx=pos[x]+1;
            swap(pos[x], pos[a[right_idx]]);
            swap(a[now_idx], a[right_idx]);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}