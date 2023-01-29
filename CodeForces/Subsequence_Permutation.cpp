#include<bits/stdc++.h>
using namespace std;
char str[45],cpy[45];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,cnt=0;
        scanf("%d%s",&n,str);
        for(i=0;i<n;i++){
            cpy[i]=str[i];
        }
        sort(str,str+n);
        for(i=0;i<n;i++){
            if(str[i]!=cpy[i]){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}