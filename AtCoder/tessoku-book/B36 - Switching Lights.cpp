#include<bits/stdc++.h>
using namespace std;
char str[300010];
int main(){
    int n,k;
    scanf("%d%d%s",&n,&k,str);

    int one_cnt=0;
    for(int i=0;i<n;i++){
        if(str[i]=='1'){
            one_cnt++;
        }
    }
    if(k%2==one_cnt%2){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}