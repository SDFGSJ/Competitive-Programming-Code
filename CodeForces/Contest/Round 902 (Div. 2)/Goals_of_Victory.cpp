#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,num,sum=0;
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            scanf("%d",&num);
            sum+=num;
        }
        printf("%d\n",-sum);
    }
    return 0;
}