#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main(){
    int n;
    scanf("%d",&n);
    int amax=INT_MIN;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        amax=max(amax,a[i]);
    }

    int bmax=INT_MIN;
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        bmax=max(bmax,b[i]);
    }
    printf("%d\n",amax+bmax);
    return 0;
}