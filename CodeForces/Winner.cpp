#include<bits/stdc++.h>
using namespace std;
struct player{
    string name;
    int score;
};
player p[1010]; //record the game
map<string,int> m;  //<name:score>
set<string> winners;    //winners who have the same Max score
multiset<int> s;    //record all kinds of scores
int main(){
    int n,Max=-1e9,i;
    string winner;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        cin>>p[i].name>>p[i].score;
        m[ p[i].name ] += p[i].score;
    }
    for(auto i:m){
        s.insert(i.second);
        if(Max<i.second){
            Max=i.second;
            winner=i.first;
        }
    }
    if(s.count(Max)>1){ //mutliple winner
        for(auto i:m){
            if(i.second==Max){
                winners.insert(i.first);
            }
        }
        m.clear();
        for(i=0;i<n;i++){
            if(winners.count(p[i].name) > 0){   //if this player is one of the winners
                m[p[i].name]+=p[i].score;
                if(m[p[i].name]>=Max){
                    winner=p[i].name;
                    break;
                }
            }
        }
    }
    cout<<winner<<'\n';
    return 0;
}