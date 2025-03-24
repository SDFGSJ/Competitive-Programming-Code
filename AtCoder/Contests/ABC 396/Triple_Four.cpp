#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i+2<n;i++){
        if(a[i]==a[i+1] && a[i+1]==a[i+2]){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}