#include<bits/stdc++.h>
using namespace std;
int a[15];
bool istrap[100010],can_step[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int b;
        scanf("%d",&b);
        istrap[b]=true;
    }
    int x;
    scanf("%d",&x);

    can_step[0]=true;   //initially at step 0
    for(int i=0;i<=x;i++){
        if(can_step[i] && !istrap[i]){
            for(int j=0;j<n;j++){
                if(i+a[j]<=100000){
                    can_step[i+a[j]]=true;
                }
            }
        }
    }

    if(can_step[x]){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
/*
istrap[i] = true if stair i has trap on it
can_step[i] = true if we can reach stair i
*/