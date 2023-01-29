#include<bits/stdc++.h>
using namespace std;
char str[55];
int main(){
    int len,k,i,j;
    scanf("%d%d%s",&len,&k,str);

    //ex.aba=>ab[a]ba,pos=2
    //ex.aaa=>a[aa]a,pos=1
    for(i=1;i<len;i++){
        bool good=true;
        for(j=0;i+j<len;j++){
            if(str[i+j]!=str[j]){
                good=false;
                break;
            }
        }
        if(good){
            break;
        }
    }

    int pos=i;
    //repeat the identical part k times
    for(i=0;i<k;i++){
        for(j=0;j<pos;j++){
            printf("%c",str[j]);
        }
    }
    //print the rest part
    for(i=pos;i<len;i++){
        printf("%c",str[i]);
    }
    return 0;
}