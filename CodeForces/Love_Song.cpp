#include<bits/stdc++.h>
using namespace std;
char str[100010];
int a[100010];  //the len from 0~i
int main(){
    int i;
    int len,q;
    scanf("%d%d",&len,&q);
    scanf("%s",str);

    a[0]=str[0]-'a'+1;
    for(i=1;i<len;i++){
        a[i]=a[i-1]+str[i]-'a'+1;
        
    }
    /*for(i=0;i<len;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }*/
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        l--,r--;
        printf("%d\n",a[r]-a[l-1]);
    }
    return 0;
}