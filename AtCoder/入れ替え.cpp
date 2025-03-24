#include<bits/stdc++.h>
using namespace std;
int a[10]={0,1,2,3,4,5,6};
int main(){
    int n;
    scanf("%d",&n);
    n%=30;
    for(int i=0;i<n;i++){
        int idx=i%5+1;  //1-indexed
        swap(a[idx],a[idx+1]);
    }
    for(int i=1;i<=6;i++){
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
/*
cycle length = 30
take the mod of n and do the remaining operations
*/