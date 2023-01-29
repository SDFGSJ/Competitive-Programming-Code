#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[200010];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        a[i]=make_pair(num,i);
    }
    sort(a+1,a+1+n);
    printf("%d\n",a[n-1].second);
    return 0;
}