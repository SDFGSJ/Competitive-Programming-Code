#include<bits/stdc++.h>
using namespace std;
bool valid(int n,int num){
    int sum=0;
    for(int i=n-1;i>=0;i--){
        if((num>>i)&1){
            sum--;
        }else{
            sum++;
        }
        if(sum<0){
            return false;
        }
    }
    return sum==0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<1<<n;i++){    //0 for '(', 1 for ')'
        if(valid(n,i)){
            for(int j=n-1;j>=0;j--){
                if((i>>j)&1){
                    printf(")");
                }else{
                    printf("(");
                }
            }
            printf("\n");
        }
    }
    return 0;
}