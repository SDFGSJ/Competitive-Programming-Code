#include<bits/stdc++.h>
using namespace std;
bool dislike[10];
bool valid(int price){
    while(price){
        int digit=price%10;
        if(dislike[digit]){
            return false;
        }
        price/=10;
    }
    return true;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        int num;
        scanf("%d",&num);
        dislike[num]=true;
    }

    int price;
    for(price=n;;price++){
        if(valid(price)){
            printf("%d\n",price);
            break;
        }
    }
    return 0;
}
/*
brute force
*/