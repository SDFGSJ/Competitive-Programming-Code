#include<bits/stdc++.h>
using namespace std;
char s[200010];
int main(){
    int n;
    scanf("%d%s",&n,s+1);

    int ans=-1;
    for(int i=1;i<=n;i++){
        if(s[i]=='/'){
            int cnt=1;
            for(int l=i-1, r=i+1;l>=1 && r<=n;l--, r++){
                if(s[l]=='1' && s[r]=='2'){
                    cnt+=2;
                }else{
                    break;
                }
            }
            //printf("cnt=%d\n",cnt);
            ans=max(ans,cnt);
        }
    }
    printf("%d\n",ans);
    return 0;
}