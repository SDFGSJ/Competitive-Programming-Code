#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    if(n/100==n%10){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}