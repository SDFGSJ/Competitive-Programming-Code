#include<bits/stdc++.h>
using namespace std;
char a[505][505];
int r,c;
bool bad(int i,int j){    //inside the map and next to wolf
    if(0<=i && i<r && 0<=j && j<c && a[i][j]=='W'){
        return true;
    }else{
        return false;
    }
}
void put(int i,int j){  //put the dog on the map only when a[i][j] is '.'
    if(0<=i && i<r && 0<=j && j<c && a[i][j]=='.'){
        a[i][j]='D';
    }
}
int main(){
    int i,j;
    bool no=false;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++){
        scanf("%s",&a[i]);
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]=='S'){
                if(bad(i-1,j) || bad(i+1,j) || bad(i,j-1) || bad(i,j+1)){
                    no=true;
                    break;
                }else{
                    put(i-1,j);put(i+1,j);
                    put(i,j-1);put(i,j+1);
                }
            }
        }
        if(no){
            break;
        }
    }

    if(no){
        printf("No\n");
    }else{
        printf("Yes\n");
        for(i=0;i<r;i++){
            printf("%s\n",a[i]);
        }
    }
    return 0;
}
//can also put dog on every empty places