#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,up=-1,down;  //C(up,down)
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        up=max(up,a[i]);    //max up is the best choice
    }

    for(int i=0;i<n;i++){
        if(a[i]==up){
            a[i]=-1;    //can't choose up again
        }
    }

    //pascal triangle
    int mid1,mid2;
    if(up%2==0){
        mid1=mid2=up/2;
    }else{
        mid1=up/2;
        mid2=(up+1)/2;
    }

    int min_dist=INT_MAX;
    for(int i=0;i<n;i++){
        if(abs(a[i]-mid1)+abs(a[i]-mid2)<min_dist){
            min_dist=abs(a[i]-mid1)+abs(a[i]-mid2);
            down=a[i];
        }
    }
    printf("%d %d\n",up,down);
    return 0;
}