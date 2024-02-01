#include<bits/stdc++.h>
using namespace std;
char grid[10][10];
vector<pair<int,int>> v;
int dist(int i,int j){
    return
    (v[i].first-v[j].first)*(v[i].first-v[j].first) +
    (v[i].second-v[j].second)*(v[i].second-v[j].second);
}
bool is_square(int i,int j,int k,int l){
    set<int> s;
    s.emplace(dist(i,j));
    s.emplace(dist(i,k));
    s.emplace(dist(i,l));
    s.emplace(dist(j,k));
    s.emplace(dist(j,l));
    s.emplace(dist(k,l));
    return s.size()==2;
}
int main(){
    for(int i=0;i<9;i++){
        scanf("%s",grid[i]);
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]=='#'){
                v.emplace_back(i,j);
            }
        }
    }

    int cnt=0;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
                for(int l=k+1;l<v.size();l++){
                    if(is_square(i,j,k,l)){
                        cnt++;
                    }
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}