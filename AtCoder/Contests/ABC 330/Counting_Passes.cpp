#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    int cnt=0;
    for(int i=0;i<n;i++){
        int score;
        scanf("%d",&score);
        if(score>=l){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}