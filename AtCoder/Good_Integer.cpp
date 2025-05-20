#include<bits/stdc++.h>
using namespace std;
vector<int> dist[10];   //dist[i] = list of idx where number i appears in n
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<4;i++){
        dist[n%10].emplace_back(i);
        n/=10;
    }
    for(int i=0;i<=9;i++){
        if(dist[i].size()>=3 && dist[i][0]+1==dist[i][1] && dist[i][1]+1==dist[i][2]){
            printf("Yes\n");
            exit(0);
        }
    }
    printf("No\n");
    return 0;
}