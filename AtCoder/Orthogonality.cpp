#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }

    int sum=0;
    for(i=0;i<n;i++){
        sum+=a[i]*b[i];
    }
    if(sum==0){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}