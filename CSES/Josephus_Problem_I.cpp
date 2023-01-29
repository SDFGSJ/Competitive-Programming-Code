#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n,people,idx,i;
    scanf("%d",&n);

    //array simulation
    for(i=1;i<=n;i++){
        a[i]=i;
    }

    people=n,idx=0;
    while(people>1){
        int cnt=0;
        while(cnt<2){
            if(idx<n){
                idx++;
            }else{
                idx=1;
            }

            if(a[idx]!=-1){
                cnt++;
            }
        }
        printf("%d ",a[idx]);
        a[idx]=-1;
        people--;
    }

    //find the last person
    for(i=1;i<=n;i++){
        if(a[i]!=-1){
            break;
        }
    }
    printf("%d",a[i]);
    return 0;
}