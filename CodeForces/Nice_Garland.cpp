#include<bits/stdc++.h>
using namespace std;
char first[5]="RGB",second[5]="RBG",str[200010];
int main(){
    int len,t,i,cnt=0,mymin=1e9;    //the number of differrent chars in two string
    string f,s,ans;
    scanf("%d%s",&len,str);

    //special case
    if(len==1){
        printf("0\n%s\n",str);
        return 0;
    }
    if(len==2){
        if(str[0]==str[1]){
            printf("1\n");
            if(str[0]=='R'){
                printf("RG\n");
            }else if(str[0]=='G'){
                printf("GB\n");
            }else{
                printf("BR\n");
            }
        }else{
            printf("0\n%s\n",str);
        }
        return 0;
    }


    for(i=0;i<len;i++){
        f.push_back(first[i%3]);
    }
    for(i=0;i<len;i++){
        s.push_back(second[i%3]);
    }

    //enumerate by putting [len%3] to the last and take the substring [1:]
    for(t=0;t<3;t++){
        cnt=0;
        for(i=0;i<len;i++){
            if(str[i]!=f[i]){
                cnt++;
            }
        }
        if(cnt<mymin){
            mymin=cnt;
            ans=f;
        }
        f.push_back(f[len%3]);
        f=f.substr(1);
    }
    for(t=0;t<3;t++){
        cnt=0;
        for(i=0;i<len;i++){
            if(str[i]!=s[i]){
                cnt++;
            }
        }
        if(cnt<mymin){
            mymin=cnt;
            ans=s;
        }
        s.push_back(s[len%3]);
        s=s.substr(1);
    }
    printf("%d\n%s\n",mymin,ans.c_str());
    return 0;
}