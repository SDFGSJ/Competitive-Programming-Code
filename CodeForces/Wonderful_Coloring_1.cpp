#include<bits/stdc++.h>
using namespace std;
char str[55];
int cnt[26];
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int num=0;
        scanf("%s",str);
        for(i=0;i<26;i++){
            cnt[i]=0;
        }
        for(i=0;str[i]!='\0';i++){
            cnt[str[i]-'a']++;
        }
        /*for(i=0;i<26;i++){
            printf("%d,",cnt[i]);
        }
        printf("\n");*/
        for(i=0;i<26;i++){
            if(cnt[i]>2){
                cnt[i]=2;
            }
            num+=cnt[i];
        }
        printf("%d\n",num/2);
    }
    return 0;
}