#include<bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
    int t;
    scanf("%s%d",s,&t);

    int l=0,r=0,u=0,d=0,q=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='L'){
            l++;
        }else if(s[i]=='R'){
            r++;
        }else if(s[i]=='U'){
            u++;
        }else if(s[i]=='D'){
            d++;
        }else{
            q++;
        }
    }

    int ch=abs(l-r)+abs(u-d),ans=0;
    if(t==1){
        ans=ch+q;
    }else{
        if(ch>q){
            ans=ch-q;
        }else{
            ans=(q-ch)%2;
        }
    }
    printf("%d\n",ans);
    return 0;
}