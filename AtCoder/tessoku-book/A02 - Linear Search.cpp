#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(num==x){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}