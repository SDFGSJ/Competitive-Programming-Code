#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,cnt5=0,cnt7=0,i;
    for(i=0;i<3;i++){
        scanf("%d",&num);
        if(num==5){
            cnt5++;
        }else if(num==7){
            cnt7++;
        }
    }
    if(cnt5==2 && cnt7==1){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}