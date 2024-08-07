#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int diff=0;
    for(int i=0;i<n;i++){
        diff+=abs(a[i]-b[i]);
    }
    if(diff<=k && (k-diff)%2==0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}