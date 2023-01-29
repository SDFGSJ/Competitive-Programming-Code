#include<bits/stdc++.h>
using namespace std;
int ans[1010];
int main(){
    int n,i,j,idx=0;
    bool isprime=false;
    set<int> prime;
    scanf("%d",&n);

    //find all prime numbers between 2~n
    for(i=2;i<=n;i++){
        isprime=true;
        for(j=2;j*j<=i;j++){
            if(i%j==0){
                isprime=false;
                break;
            }
        }
        if(isprime){
            prime.insert(i);
        }
    }

    for(auto i:prime){
        int tmp=i;
        while(tmp<=n){
            ans[idx]=tmp;
            idx++;
            tmp*=i;
        }
    }
    
    printf("%d\n",idx);
    for(i=0;i<idx;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}