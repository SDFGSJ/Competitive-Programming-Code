#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n,i,sum=0,my=0,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    sort(a,a+n,greater<int>());

    i=0;
    while(my<=sum){
        my+=a[i];
        sum-=a[i];
        i++;
        cnt++;
    }
    
    printf("%d\n",cnt);
}