#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,num=1,i,j;
    scanf("%d",&n);

    for(i=2;i<=n;i++){
        if(a[i]==0){
            for(j=i;j<=n;j+=i){
                a[j]=num;
            }
            num++;
        }
    }
    for(i=2;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}