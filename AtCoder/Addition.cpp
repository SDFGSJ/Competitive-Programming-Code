#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num,odd=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(num&1){
            odd++;
        }
    }
    if(odd&1){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    return 0;
}