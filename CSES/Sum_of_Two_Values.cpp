#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> m;    //<value,index>
int num[200010];
int main(){
    int n,target,i;
    bool haveans=false;
    scanf("%d%d",&n,&target);
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);
        m[num[i]].push_back(i);
    }

    //sort the array to apply BS
    sort(num+1,num+1+n);

    for(i=1;i<=n;i++){
        if(binary_search(num+1+i,num+1+n,target-num[i])){
            if(target==num[i]*2){   //beware of this case,cant output two same index
                printf("%d %d\n", m[num[i]][0], m[target-num[i]][1]);
            }else{
                printf("%d %d\n", m[num[i]][0], m[target-num[i]][0]);
            }
            haveans=true;
            break;
        }
    }
    if(!haveans){
        printf("IMPOSSIBLE\n");
    }
    return 0;
}