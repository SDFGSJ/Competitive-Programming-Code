#include<bits/stdc++.h>
using namespace std;
int a[200010];
int idx[200010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,i,j;
        int l=1e9,r=-1e9;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            idx[a[i]]=i;    //notice that idx[] starts from 1
        }
        for(i=1;i<=n;i++){
            l=min(l,idx[i]);
            r=max(r,idx[i]);
            //if [l,r] contains m consecutive numbers,then r-l+1==m
            if(r-l+1==i){
                printf("1");
            }else{
                printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}