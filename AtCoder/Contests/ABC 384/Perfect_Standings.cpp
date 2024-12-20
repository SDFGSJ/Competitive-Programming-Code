#include<bits/stdc++.h>
using namespace std;
int score[5];
vector<pair<int,string>> v;
int main(){
    for(int i=0;i<5;i++){
        scanf("%d",&score[i]);
    }

    for(int bit=1;bit<=31;bit++){
        string s;
        int sum=0;
        for(int i=0;i<5;i++){
            if(bit&(1<<i)){
                sum+=score[i];
                s+=('A'+i);
            }
        }
        v.emplace_back(-sum,s);
    }
    sort(v.begin(),v.end());
    for(auto [score,name]:v){
        cout<<name<<'\n';
    }
    return 0;
}