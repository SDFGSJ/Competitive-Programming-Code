#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",n);
    for(int i=1;i+1<=n;i++){
        printf("%d %d\n",i,i+1);
    }
    printf("%d 1\n",n);
    return 0;
}