#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    int n,m,sum=0,cnt=0,i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    for(i=0;i<n;i++){
        if(a[i]*4*m>=sum){
            cnt++;
        }
    }
    if(cnt>=m){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}