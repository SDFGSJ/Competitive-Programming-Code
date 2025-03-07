#include<bits/stdc++.h>
using namespace std;
char G[105][105];
int dist[105][105]; //dist[i][j] = shortest palindrome length from i to j
void bfs(int n){
    queue<pair<int,int>> q;

    //empty string
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
        q.emplace(i,i);
    }

    //direct edges
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            if(G[i][j]!='-'){
                dist[i][j]=1;
                q.emplace(i,j);
            }
        }
    }

    while(!q.empty()){
        auto [i,j]=q.front();q.pop();

        //enumerate new source, destination point. src -> i -> j -> dest
        for(int src=1;src<=n;src++){
            for(int dest=1;dest<=n;dest++){
                if(G[src][i]!='-' && G[src][i]==G[j][dest] && dist[src][dest]==INT_MAX){
                    dist[src][dest]=dist[i][j]+2;
                    q.emplace(src,dest);
                }
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",G[i]+1);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=INT_MAX;
        }
    }

    bfs(n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INT_MAX){
                dist[i][j]=-1;
            }
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
bfs
construct the palindrome from middle to both sides
we append the same characters to the front and back of the string
make sure that it is still a palindrome after appending characters
*/