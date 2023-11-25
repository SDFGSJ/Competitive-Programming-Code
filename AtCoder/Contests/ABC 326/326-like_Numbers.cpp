#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=n;;i++){
        int hund=i/100;
        int ten=(i%100)/10;
        int one=i%10;
        if(hund*ten==one){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}