#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    printf("%d\n",a[n-1]+a[n-2]);
    return 0;
}