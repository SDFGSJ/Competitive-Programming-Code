#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        bool no=false;
        int n,Max=-101;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]<0){
                no=1;
            }
            if(a[i]>Max){
                Max=a[i];
            }
        }
        if(no){
            printf("No\n");
        }else{
            printf("Yes\n");
            printf("%d\n",Max+1);
            for(i=0;i<=Max;i++){
                printf("%d ",i);
            }
            printf("\n");
        }
    }
    return 0;
}