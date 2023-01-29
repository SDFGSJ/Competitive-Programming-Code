#include<bits/stdc++.h>
using namespace std;
int a[55];
int main(){
    int n,k,sum=0,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    sort(a,a+n,greater<int>());
    for(i=0;i<k;i++){
        sum+=a[i];
    }
    printf("%d\n",sum);
    return 0;
}