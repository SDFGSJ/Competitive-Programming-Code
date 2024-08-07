#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    bitset<10> bs=bitset<10>(n-1);
    for(int i=9;i>=0;i--){
        if(bs[i]){
            printf("7");
        }else{
            printf("4");
        }
    }
    printf("\n");
    return 0;
}