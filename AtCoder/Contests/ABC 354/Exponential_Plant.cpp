#include<bits/stdc++.h>
using namespace std;
int main(){
    int h;
    scanf("%d",&h);
    int num=0,days=0;
    while(num<=h){
        num+=1<<days;
        days++;
    }
    printf("%d\n",days);
    return 0;
}