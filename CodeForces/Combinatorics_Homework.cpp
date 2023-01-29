#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int a[3],m,mymax=-1,mymin=1e9;
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&m);

        sort(a,a+3);

        //put the same char together to get max,ex.aabbbccc
        mymax=a[0]-1 + a[1]-1 + a[2]-1;

        /*put a different char next to each char to get min,
        so put the other two char next to the char that has the most occurence
        and then -1*/
        mymin=max(a[2]-a[0]-a[1]-1,0);

        if(mymin<=m && m<=mymax){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}