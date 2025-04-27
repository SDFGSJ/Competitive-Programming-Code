#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        if(i&1){
            sum+=num;
        }
    }
    printf("%d\n",sum);
    return 0;
}