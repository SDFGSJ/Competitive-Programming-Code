#include<bits/stdc++.h>
using namespace std;
char s[1010];
int main(){
    int n,m;
    scanf("%d%d%s",&n,&m,s);
    for(int logo=0;logo<=1000;logo++){
        int plain_used=0,logo_used=0;
        bool isans=true;
        for(int j=0;j<n && isans;j++){
            if(s[j]=='0'){
                plain_used=0;
                logo_used=0;
            }else if(s[j]=='1'){
                if(plain_used<m){
                    plain_used++;
                }else if(logo_used<logo){
                    logo_used++;
                }else{
                    isans=false;
                }
            }else{
                if(logo_used<logo){
                    logo_used++;
                }else{
                    isans=false;
                }
            }
            //printf("logo=%d,plain_used=%d, logo_used=%d\n",logo,plain_used,logo_used);
        }
        if(isans){
            printf("%d\n",logo);
            return 0;
        }
    }
    return 0;
}