#include<bits/stdc++.h>
using namespace std;
char a[200010];
int main(){
    int t,n,k,i,j;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf("%d%d",&n,&k);
        scanf("%s",a);
        i=0;
        while(i<n){
            if(a[i]=='B'){
                for(j=i;j<i+k && j<n;j++){
                    a[j]='W';
                }
                i=j;
                cnt++;
            }else{
                i++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}