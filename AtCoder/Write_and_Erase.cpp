#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int main(){
    int n,cnt=0,i;
    scanf("%d",&n);

    int num;
    for(i=0;i<n;i++){
        scanf("%d",&num);
        m[num]++;
    }

    for(auto entry : m){
        if(entry.second%2){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}