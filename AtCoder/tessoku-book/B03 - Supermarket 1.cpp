#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k]==1000){
                    printf("Yes\n");
                    return 0;
                }
            }
        }
    }
    printf("No\n");
    return 0;
}