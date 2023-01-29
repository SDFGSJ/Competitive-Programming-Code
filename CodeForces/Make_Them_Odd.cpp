#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        set<int,greater<int>> s;
        int n,num,cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&num);
            if(num%2==0){                
                s.insert(num);
            }
        }
        for(auto it=s.begin();it!=s.end();){
            if(*it%4==0){   //if this num/2 is still even,then it should be inserted to s
                s.insert(*it/2);
            }
            //if this num/2 is odd,then we dont care
            it=s.erase(it);
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}