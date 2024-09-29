#include<bits/stdc++.h>
using namespace std;
char s[200010];
int dp[200010][3];
string you="SPR";
void update(int oppo_idx,int you_idx,int score){
    int mymax=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=you_idx){ //what you play should be different from the last round
            mymax=max(mymax, dp[oppo_idx-1][i]);
        }
    }
    dp[oppo_idx][you_idx]=mymax+score;
}
int main(){
    int n;
    scanf("%d%s",&n,s+1);
    map<char,char> win={{'P','S'}, {'S','R'}, {'R','P'}};

    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            if(win[you[j]]==s[i]){  //lose
                dp[i][j]=INT_MIN;   //never lose
                //update(i,j,-1);   //WA
            }else if(win[s[i]]==you[j]){    //win
                update(i,j,1);
            }else{  //even
                update(i,j,0);
            }
        }
    }
    printf("%d\n",max({dp[n][0], dp[n][1], dp[n][2]}));
    return 0;
}
/*
dp[i][0] = max # of winning in round 1~i when you are 'S' on the i-th round
dp[i][1] = max # of winning in round 1~i when you are 'P' on the i-th round
dp[i][2] = max # of winning in round 1~i when you are 'R' on the i-th round
*/