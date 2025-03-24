#include<bits/stdc++.h>
using namespace std;
int a[6];
int main(){
    for(int i=1;i<=5;i++){
        scanf("%d",&a[i]);
    }

    bool swapped=false;
    for(int i=1;i<=4;i++){
        if(a[i]!=i){
            swap(a[i],a[i+1]);
            swapped=true;
            break;
        }
    }

    if(!swapped){
        printf("No\n");
        exit(0);
    }

    for(int i=1;i<=5;i++){
        if(a[i]!=i){
            printf("No\n");
            exit(0);
        }
    }
    printf("Yes\n");
    return 0;
}