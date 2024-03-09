#include<bits/stdc++.h>
using namespace std;
int a[200010];
unordered_map<int,int> front,back;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    front[a[0]]=-1;back[-1]=a[0];
    back[a[n-1]]=0;front[0]=a[n-1];
    for(int i=0;i+1<n;i++){
        back[a[i]]=a[i+1];
        front[a[i+1]]=a[i];
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int op,x;
        scanf("%d%d",&op,&x);
        int xfront=front[x],xback=back[x];
        if(op==1){
            int y;
            scanf("%d",&y);
            back[y]=xback;front[xback]=y;
            back[x]=y;front[y]=x;
        }else{
            back[xfront]=xback;
            front[xback]=xfront;
            front.erase(x);back.erase(x);
        }
    }
    int now=-1;
    while(1){
        now=back[now];
        if(now==0){
            break;
        }
        printf("%d ",now);
    }
    printf("\n");
    return 0;
}
//doubly linked list