#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,x,i;
    scanf("%d%d",&n,&x);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]!=x){
            printf("%d ",a[i]);
        }
    }
    printf("\n");
    return 0;
}