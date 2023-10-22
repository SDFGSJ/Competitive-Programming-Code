#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
char str[105][105];
int score[105],mymax=-1;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int score;
        scanf("%d",&score);
        v.emplace_back(score,i);    // <score, problem id>
    }
    
    for(int i=0;i<n;i++){   // each player
        scanf("%s",str[i]);
        for(int j=0;j<m;j++){   //each problem
            if(str[i][j]=='o'){
                score[i]+=v[j].first;
            }
        }
        score[i]+=(i+1);    //bonus
        mymax=max(mymax,score[i]);
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<n;i++){
        int diff=mymax-score[i],cnt=0;
        for(int j=0;diff>0 && j<m;j++){
            int id=v[j].second; // problem id
            if(str[i][id]=='x'){
                diff-=v[j].first;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}