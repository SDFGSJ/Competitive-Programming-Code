#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int ans=0;
    if((a<=c && d<=b) || (c<=a && b<=d)){   //a-c-d-b or c-a-b-d => choose the smaller length
        ans=min(b-a,d-c);
    }else if(b<=c || d<=a){ //does not intersect, (a-b c-d) or (c-d a-b)
        ans=0;
    }else{  //partially intersect
        if(a<=c && c<=b){   //a-c-b-d
            ans=b-c;
        }else{  //c-a-d-b
            ans=d-a;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
divide by cases
*/