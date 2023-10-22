#include<bits/stdc++.h>
using namespace std;
char str[105];
int cnt[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",str);
        for(int j=0;j<n;j++){
            if(str[j]=='o'){
                cnt[i]++;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(cnt[j]==i){
                printf("%d ",j+1);
            }
        }
    }
    return 0;
}