#include<bits/stdc++.h>
using namespace std;
char s[200010],t[200010];
vector<char> ans;
int main(){
    int q;
    scanf("%s%d",s,&q);
    int len=strlen(s);

    for(int i=0;s[i]!='\0';i++){
        if(isupper(s[i])){
            t[i]=tolower(s[i]);
        }else{
            t[i]=toupper(s[i]);
        }
    }

    long long k;
    for(int i=0;i<q;i++){
        scanf("%lld",&k);
        long long group=(k-1)/len;
        int idx=(k-1)%len;
        bool issame=true;
        while(group>=2){
            //find the smallest power of 2 s.t. tmp<=group<tmp*2
            long long tmp=1;
            for(int i=0;i<__lg(group);i++){
                tmp<<=1;
            }

            group-=tmp;
            issame=!issame; //mirroring
        }

        char ch;
        if(group==0){   //find the ans in s[]
            if(issame){ //the group of kth char is the same as s[]
                ch=s[idx];
            }else{
                ch=t[idx];
            }
        }else{  //find the ans in t[]
            if(issame){
                ch=t[idx];
            }else{
                ch=s[idx];
            }
        }
        ans.emplace_back(ch);
    }

    for(auto ch:ans){
        printf("%c ",ch);
    }
    printf("\n");
    return 0;
}
/*
t[] is the inverse of s[](lower <=> upper)
given kth char in the final string, find which idx at which group does the k-th char locate at?
*/