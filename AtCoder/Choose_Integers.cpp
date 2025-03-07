#include<bits/stdc++.h>
using namespace std;
bool vis[105];  //vis[i] = true if modulo i has appeared before
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;;i++){  //need to choose at least 1 integer
        int modulo=(i*a)%b;
        if(vis[modulo]){
            break;
        }
        vis[modulo]=true;
        if(modulo==c){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
/*
find the cycle of the modulo and check whether C exists in that cycle
*/