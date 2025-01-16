#include<bits/stdc++.h>
using namespace std;
bool ab[10][10],cd[10][10];
int arr[10];
bool isomorphic(int n){
    bool res=true;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ab[i][j] && !cd[arr[i]][arr[j]]){    //(i,j) has edge, but (Pi,Pj) doesnt have
                res=false;
            }
            if(!ab[i][j] && cd[arr[i]][arr[j]]){    //(i,j) doenst have edge, but (Pi,Pj) has
                res=false;
            }
        }
    }
    return res;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        ab[a][b]=ab[b][a]=true;
    }
    for(int i=0;i<m;i++){
        int c,d;
        scanf("%d%d",&c,&d);
        c--,d--;
        cd[c][d]=cd[d][c]=true;
    }

    for(int i=0;i<n;i++){
        arr[i]=i;
    }
    do{
        if(isomorphic(n)){
            printf("Yes\n");
            return 0;
        }
    }while(next_permutation(arr,arr+n));
    printf("No\n");
    return 0;
}
/*
next permutation to enumerate P
nested for loop to check whether two toys have the same shape
*/