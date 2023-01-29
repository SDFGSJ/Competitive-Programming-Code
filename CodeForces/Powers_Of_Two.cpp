#include<bits/stdc++.h>
using namespace std;
int cnt[35];    //
int main(){
    int n,k,least=0,sum=0,i,j;
    scanf("%d%d",&n,&k);

    //count the number of 1s in n's binary representation
    for(i=0;i<31;i++){
        if((n>>i)&1){
            least++;
            cnt[i]++;
        }
    }

    //starting from the last element to decompose them until sum==k
    i=30;
    sum=least;
    if(least<=k && k<=n){
        printf("YES\n");
        while(sum!=k && i-1>=0){
            if(cnt[i]!=0){
                cnt[i]--;
                cnt[i-1]+=2;
                sum++;  //-1+2 => +1
            }else{
                i--;
            }
        }
        for(i=0;i<31;i++){
            for(j=0;j<cnt[i];j++){
                printf("%d ",1<<i);
            }
        }
        printf("\n");
    }else{
        printf("NO\n");
    }
    return 0;
}