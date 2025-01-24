#include<bits/stdc++.h>
using namespace std;
int h[105];
bool allzero(int n){
    for(int i=0;i<n;i++){
        if(h[i]>0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }

    int cnt=0;
    while(!allzero(n)){
        //find the 1st plant whose height>0
        int l;
        for(l=0;l<n;l++){
            if(h[l]>0){
                break;
            }
        }

        //find the 1st r after plant l whose height>0
        int r;
        for(r=l;r<n;r++){
            if(h[r]==0){
                break;
            }
        }
        r--;
        cnt++;
        for(int i=l;i<=r;i++){
            h[i]--;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
/*
simulation
*/