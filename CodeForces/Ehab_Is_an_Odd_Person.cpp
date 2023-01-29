#include<bits/stdc++.h>
using namespace std;
int a[100010];
int cnt[2];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[ a[i]%2 ]++;
    }

    if(cnt[0]!=0 && cnt[1]!=0){
        sort(a,a+n);
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}