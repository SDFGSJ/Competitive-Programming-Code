#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++){
        if(100%i==0){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}