#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s,m,l;
    scanf("%d%d%d%d",&n,&s,&m,&l);
    int ans=INT_MAX;
    for(int i=0;i<=20;i++){ //s
        for(int j=0;j<=20;j++){ //m
            for(int k=0;k<=20;k++){ //l
                if(6*i+8*j+12*k>=n){
                    ans=min(ans,i*s+j*m+k*l);
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}