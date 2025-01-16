#include<bits/stdc++.h>
using namespace std;
int a[1005];
const int offset=10000;
int main(){
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    vector<bool> dpx(20010,false), dpy(20010,false);
    for(int i=0;i<n;i++){
        vector<bool> nextdpx(20010,false), nextdpy(20010,false);
        if(i==0){   //special case, (a[1],0) is reachable
            nextdpx[a[i]+offset]=true;
            nextdpy[0+offset]=true;
            swap(dpx,nextdpx);
            swap(dpy,nextdpy);
            continue;
        }
        if(i%2==0){ //horizontal move
            for(int j=0;j<=20000;j++){  //check each reachable coordinate
                if(dpx[j]){
                    if(j+a[i]<=20000){  //beware of index out of bound
                        nextdpx[j+a[i]]=true;
                    }
                    if(j-a[i]>=0){
                        nextdpx[j-a[i]]=true;
                    }
                }
            }
            swap(dpx,nextdpx);
        }else{
            for(int j=0;j<=20000;j++){
                if(dpy[j]){
                    if(j+a[i]<=20000){
                        nextdpy[j+a[i]]=true;
                    }
                    if(j-a[i]>=0){
                        nextdpy[j-a[i]]=true;
                    }
                }
            }
            swap(dpy,nextdpy);
        }
    }

    if(dpx[x+offset] && dpy[y+offset]){ //(x,y) is reachable <=> dpx[x+offset], dpy[y+offset] are both true
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
dp + rolling array
consider x,y separately and focus on one of them at a time
since -1e4 <= x,y <= 1e4, we declare arrays with size 20010, where
dpx[i] = true if x coordinate "i-10000" is reachable after completing all n operations
dpy[i] = true if y coordinate "i-10000" is reachable after completing all n operations

bitset sol:https://atcoder.jp/contests/abc274/submissions/61701876
*/