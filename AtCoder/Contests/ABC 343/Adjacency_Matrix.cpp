#include<bits/stdc++.h>
using namespace std;
int adj[105][105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1){
                printf("%d ",j+1);
            }
        }
        printf("\n");
    }
    return 0;
}