#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=0;
    for(int i=0;i<9;i++){
        int num;
        scanf("%d",&num);
        a+=num;
    }
    int b=0;
    for(int i=0;i<8;i++){
        int num;
        scanf("%d",&num);
        b+=num;
    }
    printf("%d\n",a-b+1);
    return 0;
}