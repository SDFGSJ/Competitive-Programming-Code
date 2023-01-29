#include<bits/stdc++.h>
using namespace std;
char str[105];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int len,a,b,cnt=0,times=0;
        scanf("%d%d%d%s",&len,&a,&b,str);
        for(i=0;i<len-1;i++){
            if(str[i]!=str[i+1]){
                cnt++;
            }
        }
        //printf("cnt=%d\n",cnt);
        if(cnt==0){
            times=1;
        }else{
            times=(cnt-1)/2+2;
        }
        printf("%d\n",max(a*len+times*b,a*len+len*b));
    }
    return 0;
}