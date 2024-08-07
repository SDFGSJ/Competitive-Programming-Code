#include<bits/stdc++.h>
using namespace std;
char a[100010];
queue<int> q;
int main(){
    int n,x;
    scanf("%d%d%s",&n,&x,a);
    x--;

    q.emplace(x);
    while(!q.empty()){
        int pos=q.front();q.pop();
        a[pos]='@';
        if(pos-1>=0 && a[pos-1]=='.'){
            q.emplace(pos-1);
        }
        if(pos+1<n && a[pos+1]=='.'){
            q.emplace(pos+1);
        }
    }
    printf("%s\n",a);
    return 0;
}