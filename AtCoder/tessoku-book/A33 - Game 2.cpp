#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        ans^=num;
    }
    if(ans==0){
        printf("Second\n");
    }else{
        printf("First\n");
    }
    return 0;
}