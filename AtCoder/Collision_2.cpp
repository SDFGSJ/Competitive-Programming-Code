#include<bits/stdc++.h>
using namespace std;
int x[200010],y[200010];
char s[200010];
unordered_map<int,int> L,R;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    scanf("%s",s);

    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            L[y[i]]=max(L[y[i]],x[i]);  //find the rightmost x coordinate of '<=' on line y=y[i]
        }else{
            if(R.find(y[i])==R.end()){  //find the leftmost x coordinate of '=>' on line y=y[i]
                R[y[i]]=x[i];
            }else{
                R[y[i]]=min(R[y[i]],x[i]);
            }
        }
    }

    for(auto [k,v]:L){
        if(R.find(k)!=R.end() && R[k]<L[k]){ //if there are '=>' on the same line y=k, check whether they will collide
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
/*
hash map
L[y] = the x coordinate of the rightmost '<=' on line Y=y
R[y] = the x coordinate of the leftmost '=>' on line Y=y
it is enough to focus only on the rightmost '<=' and the leftmost '=>'(both share the same y coordinate)
<= =>: no
=> <=:yes
*/