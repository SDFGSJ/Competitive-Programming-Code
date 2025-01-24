#include<bits/stdc++.h>
using namespace std;
char s[100010];
deque<char> dq;
void push_char(bool rev,int f,char ch){
    if(rev){
        if(f==1){
            dq.emplace_back(ch);
        }else{
            dq.emplace_front(ch);
        }
    }else{
        if(f==1){
            dq.emplace_front(ch);
        }else{
            dq.emplace_back(ch);
        }
    }
}
int main(){
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        dq.emplace_back(s[i]);
    }

    bool reversed=false;
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            reversed=!reversed;
        }else{
            int f;char ch;
            scanf("%d %c",&f,&ch);
            push_char(reversed,f,ch);
        }
    }

    if(reversed){
        for(int i=dq.size()-1;i>=0;i--){
            printf("%c",dq[i]);
        }
    }else{
        for(int i=0;i<dq.size();i++){
            printf("%c",dq[i]);
        }
    }
    printf("\n");
    return 0;
}