#include<bits/stdc++.h>
using namespace std;
int a[205];
int main(){
    int n,cnt=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    bool alleven=true;
    while(alleven){
        for(i=0;i<n;i++){
            if(a[i]%2){
                alleven=false;
                break;
            }else{
                a[i]/=2;
            }
        }
        if(alleven){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}