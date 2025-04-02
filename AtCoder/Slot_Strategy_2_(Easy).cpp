#include<bits/stdc++.h>
using namespace std;
char reels[3][105];
int main(){
    int m;
    scanf("%d",&m);
    for(int i=0;i<3;i++){
        scanf("%s",reels[i]);
    }

    int ans=INT_MAX;
    for(int i=0;i<m;i++){   //reels[0]
        for(int j=0;j<m;j++){   //reels[1]
            for(int k=0;k<m;k++){   //reels[2]
                if(reels[0][i]!=reels[1][j] ||
                    reels[1][j]!=reels[2][k] ||
                    reels[0][i]!=reels[2][k]){
                    continue;
                }
                if(i!=j && j!=k && i!=k){   //index => 3 different
                    ans=min(ans,max({i,j,k}));  //pick the latest one
                }else if(i==j && j==k){ //index => 3 same
                    ans=min(ans,i+m*2);
                }else{  //index => 2 same
                    if(i==j){
                        ans=min(ans,i+m);
                    }else if(i==k){
                        ans=min(ans,i+m);
                    }else{  //j==k
                        ans=min(ans,j+m);
                    }
                }
            }
        }
    }
    if(ans==INT_MAX){
        ans=-1;
    }
    printf("%d\n",ans);
    return 0;
}
/*
brute force
enumerate i,j,k. check the equality of i,j,k, divide by case
1. i,j,k are all same => go 2 rounds and stop at i
2. 2 of them are same => go 1 round and stop at duplicate index
3. all of them are different => stop at the latest one
*/