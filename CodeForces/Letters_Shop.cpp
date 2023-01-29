#include<bits/stdc++.h>
using namespace std;
char s[200010],name[200010];
vector<int> v[26];  //record every character's idx
int main(){
    int len,q,i;
    scanf("%d%s%d",&len,s,&q);
    for(i=0;s[i]!='\0';i++){
        v[s[i]-'a'].push_back(i+1); //the answer is 1-indexed
    }
    /*for(i=0;i<26;i++){
        printf("[%c]:",'a'+i);
        for(auto num:v[i]){
            printf("%d,",num);
        }
        printf("\n");
    }*/
    while(q--){
        scanf("%s",name);
        int cnt[26]={},mymax=-1;
        for(i=0;name[i]!='\0';i++){
            cnt[name[i]-'a']++; //reocrd each charecter's appear time
        }
        /*printf("cnt[]=");
        for(i=0;i<26;i++){
            printf("%d,",cnt[i]);
        }
        printf("\n");*/

        for(i=0;i<26;i++){  //loop through cnt and find the larger index
            if(cnt[i]!=0){
                mymax=max(mymax,v[i][cnt[i]-1]);
            }
        }
        printf("%d\n",mymax);
    }
    return 0;
}