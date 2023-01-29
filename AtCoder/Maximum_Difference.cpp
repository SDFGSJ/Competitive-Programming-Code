#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",*max_element(a,a+n) - *min_element(a,a+n));
    return 0;
}