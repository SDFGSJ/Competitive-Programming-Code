#include<bits/stdc++.h>
using namespace std;
int h1,h2,h3,w1,w2,w3;
bool valid(int i,int j,int k,int l){
    int top_right=h1-i-j, middle_right=h2-k-l, bottom_left=w1-i-k, bottom_middle=w2-j-l;
    return (top_right>=1) && (middle_right>=1) && (bottom_left>=1) && (bottom_middle>=1)
     && (h3-bottom_left-bottom_middle == w3-top_right-middle_right)
     && (h3-bottom_left-bottom_middle>=1);
}
int main(){
    scanf("%d%d%d%d%d%d",&h1,&h2,&h3,&w1,&w2,&w3);
    int ans=0;
    for(int i=1;i<=30;i++){ //top-left
        for(int j=1;j<=30;j++){ //top-middle
            for(int k=1;k<=30;k++){ //middle-left
                for(int l=1;l<=30;l++){ //middle-middle
                    if(valid(i,j,k,l)){
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}