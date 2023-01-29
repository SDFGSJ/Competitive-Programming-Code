#include<bits/stdc++.h>
using namespace std;
int a[55];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum>=n){
            printf("%d\n",sum-n);
        }else{
            printf("1\n");
        }
    }
}