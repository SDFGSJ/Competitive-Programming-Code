#include<bits/stdc++.h>
using namespace std;
int divby2,divby4,others;
bool ok(int divby2,int divby4,int others){
    /*my sol:
    if(divby4 && !others){
        return true;
    }
    if(divby4 && others){
        if(divby2){
            return divby4>=others;
        }else{
            return divby4+1>=others;
        }
    }
    if(!divby4 && others){
        return false;
    }
    if(divby2 && !divby4 && !others){
        return divby2>1;
    }*/

    //others sol
    if(divby4>=others){
        return true;
    }
    if(!divby2 && divby4+1>=others){
        return true;
    }
    return false;
}
int main(){
    int n,i;
    scanf("%d",&n);

    int num;
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(num%4==0){
            divby4++;
        }else if(num%2==0){
            divby2++;
        }else{
            others++;
        }
    }

    if(ok(divby2,divby4,others)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}