#include<bits/stdc++.h>
using namespace std;
char s[10];
int cnt[15];
int main(){
    scanf("%s",s);
    for(int i=0;i<6;i++){
        cnt[s[i]-'0']++;
    }
    if(cnt[1]==1 && cnt[2]==2 && cnt[3]==3){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}