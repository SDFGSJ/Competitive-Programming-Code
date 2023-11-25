#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        int days;
        scanf("%d",&days);
        if(i<10 || (i>=10 && i/10==i%10)){
            int num=i%10;
            while(num<=days){
                ans++;
                num=num*10+i%10;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}