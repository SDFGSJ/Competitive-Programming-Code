#include<bits/stdc++.h>
using namespace std;
char s[500010];
tuple<int,int,int> query[500010];
int main(){
    int n,q;
    scanf("%d%s%d",&n,s,&q);

    int idx=-1,upper=-1;
    for(int i=0;i<q;i++){
        int t,x;char c;
        scanf("%d%d %c",&t,&x,&c);
        query[i]={t,x,c};
        if(t==2 || t==3){   //record the last idx of operation of type 2 or 3
            upper=(t==3);
            idx=i;
        }else{
            s[x-1]=c;
        }
    }

    vector<pair<int,char>> v;   //operation of type 1 after idx(last op of type 2,3)
    for(int i=idx;i<q;i++){
        int t,x,c;
        tie(t,x,c)=query[i];
        if(t==1){
            v.emplace_back(x,c);
        }
    }

    //change all char first
    for(int i=0;i<n;i++){
        if(upper==1){
            s[i]=toupper(s[i]);
        }else if(upper==0){
            s[i]=tolower(s[i]);
        }
    }

    //operation of type 1 after idx has nothing to do with upper or lower
    for(auto [idx,ch]:v){
        s[idx-1]=ch;
    }
    printf("%s\n",s);
    return 0;
}