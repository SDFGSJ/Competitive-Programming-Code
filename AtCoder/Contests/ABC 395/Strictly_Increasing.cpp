#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    bool ok=true;
    for(int i=0;i+1<n;i++){
        if(a[i]>=a[i+1]){
            ok=false;
        }
    }

    if(ok){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}