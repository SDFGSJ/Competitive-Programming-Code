#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]=-a[i];
    }

    sort(a,a+n);

    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        int cnt=a+n-upper_bound(a,a+n,-x);
        printf("%d\n",cnt);
    }
    return 0;
}