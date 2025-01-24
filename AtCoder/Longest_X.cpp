#include<bits/stdc++.h>
using namespace std;
char s[200010];
int main(){
    int k;
    scanf("%s%d",s+1,&k);
    int len=strlen(s+1);

    int cnt=0,ans=0;    //the min possible ans is 0(S="...", K=0), not 1
    for(int r=1,l=1;r<=len;r++){
        if(s[r]=='.'){
            cnt++;
        }
        while(cnt>k){   //move left bound to make # of '.' <= k
            if(s[l]=='.'){
                cnt--;
            }
            l++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%d\n",ans);
    return 0;
}
/*
2 pointers
store str using 1 indexed
enumerate right bound and move left bound accordingly to satisfy problem constraints
*/