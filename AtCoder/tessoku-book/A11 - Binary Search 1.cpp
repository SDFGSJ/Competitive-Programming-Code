#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int idx=lower_bound(a,a+n,x)-a+1;
    printf("%d\n",idx);
    return 0;
}