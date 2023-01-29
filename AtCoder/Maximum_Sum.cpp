#include<bits/stdc++.h>
using namespace std;
int a[3];
int main(){
    int k,i;
    for(i=0;i<3;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);

    sort(a,a+3);
    printf("%d\n",a[0] + a[1] + a[2]*(1<<k));
    return 0;
}