#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i+1<n;i++){
        printf("%d ",a[i]*a[i+1]);
    }
    return 0;
}