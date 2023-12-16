#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,g,m;
    scanf("%d%d%d",&k,&g,&m);
    int cnt=0,glass=0,mug=0;
    while(cnt<k){
        if(glass==g){
            glass=0;
            cnt++;
        }
        if(cnt>=k){
            break;
        }
        if(mug==0){
            mug=m;
            cnt++;
        }
        if(cnt>=k){
            break;
        }

        int transfer=min(g-glass,mug);
        glass+=transfer;
        mug-=transfer;
        cnt++;
    }
    printf("%d %d\n",glass,mug);
    return 0;
}