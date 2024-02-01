#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);

    int ans=INT_MAX;
    for(int i=1;i<=n;i++){  //enumerate
        for(int j=1;j*j<=i;j++){    //divisor
            if(i%j==0){
                ans=min(ans, abs(j-i/j)+n-i);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}