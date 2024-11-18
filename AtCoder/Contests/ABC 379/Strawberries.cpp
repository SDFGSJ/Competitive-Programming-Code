#include<bits/stdc++.h>
using namespace std;
char s[105];
int main(){
    int n,k;
    scanf("%d%d%s",&n,&k,s);

    int ans=0;
    for(int l=0;l+k<=n;){
        bool isans=true;
        for(int i=0;i<k;i++){
            if(s[l+i]=='X'){
                isans=false;
            }
        }
        if(isans){
            l+=k;
            ans++;
        }else{
            l++;
        }
    }
    printf("%d\n",ans);
    return 0;
}