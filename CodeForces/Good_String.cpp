#include<bits/stdc++.h>
using namespace std;
int main(){
    int len,cnt=0;
    string s;
    cin>>len>>s;

    for(auto it1=s.begin(),it2=it1+1; it1!=s.end() && it2!=s.end();){
        //printf("%c %c\n",*it1,*it2);
        if(*it1==*it2){
            s.erase(it2);
            cnt++;
        }else{
            advance(it1,2);
            advance(it2,2);
        }
    }
    if(s.length()%2==1){
        s.pop_back();
        cnt++;
    }

    cout<<cnt<<'\n'<<s<<'\n';
    return 0;
}