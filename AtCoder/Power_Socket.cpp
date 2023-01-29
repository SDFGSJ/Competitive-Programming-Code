#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,socket=1,cnt=0;
    scanf("%d%d",&a,&b);
    
    while(socket<b){
        socket=socket-1+a;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}