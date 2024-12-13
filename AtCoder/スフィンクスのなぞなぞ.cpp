#include<bits/stdc++.h>
using namespace std;
int N,M;
bool valid(int elder){
    if((M-2*N-elder)%2){
        return false;
    }

    int child=(M-2*N-elder)/2, adult=N-elder-child;
    if(adult>=0 && elder>=0 && child>=0){
        printf("%d %d %d\n",adult,elder,child);
        return true;
    }

    return false;
}
int main(){
    scanf("%d%d",&N,&M);

    for(int elder=0;elder<=N;elder++){
        if(valid(elder)){
            return 0;
        }
    }
    printf("-1 -1 -1 \n");
    return 0;
}
/*
2adult + 3elder + 4child = M
adult + elder + child = N
=> elder + 2child = M-2N
enumerate # of elder people and find whether there exists # of child s.t. M-2N-elder is even
*/