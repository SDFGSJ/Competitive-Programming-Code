#include<bits/stdc++.h>
using namespace std;
deque<char> de;
int main(){
    int n;
    unsigned long long x;
    string str;
    cin>>n>>x>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='U' && !de.empty() && (de.back()=='L' || de.back()=='R')){   //cancel "RU" or "LU"
            de.pop_back();
        }else{
            de.emplace_back(str[i]);
        }
    }
    for(auto ch:de){
        if(ch=='L'){
            x*=2;
        }else if(ch=='R'){
            x=2*x+1;
        }else{
            x/=2;
        }
    }
    cout<<x<<'\n';
    return 0;
}