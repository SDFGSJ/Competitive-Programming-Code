#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    int sum=0;
    for(int i=0;i<n;i++){
        int score;
        scanf("%d",&score);
        if(score<=x){
            sum+=score;
        }
    }
    printf("%d\n",sum);
    return 0;
}