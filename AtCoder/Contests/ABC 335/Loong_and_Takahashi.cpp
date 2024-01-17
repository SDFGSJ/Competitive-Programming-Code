#include<bits/stdc++.h>
using namespace std;
int table[100][100];
int main(){
    int n;
    scanf("%d",&n);
    int now=1, end=n*n, sr=0, sc=-1, er=n-1, ec = n-1;
    while(now<=end){
        for (int j = ++sc; j <= ec; j++)
            table[sr][j] = now++;
        for (int i = ++sr; i <= er; i++)
            table[i][ec] = now++;
        for (int j = --ec; j >= sc; j--)
            table[er][j] = now++;
        for (int i = --er; i >= sr; i--)
            table[i][sc] = now++;
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(i==(n+1)/2-1 && j==(n+1)/2-1){
                printf("T ");
            }else{
                printf("%d ",table[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}