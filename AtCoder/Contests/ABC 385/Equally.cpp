#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int m=min({a,b,c}), M=max({a,b,c});
    if(a==b && b==c){   //3 groups
        printf("Yes\n");
    }else if(m+(a+b+c-m-M) == M){   //2 groups
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}