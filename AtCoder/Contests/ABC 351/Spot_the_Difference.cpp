#include<bits/stdc++.h>
using namespace std;
char a[105][105],b[105][105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%s",b[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=b[i][j]){
                printf("%d %d\n",i+1,j+1);
                return 0;
            }
        }
    }
    return 0;
}