#include<bits/stdc++.h>
using namespace std;
vector<pair<int,bool>> v;
int main(){
    int n,num,i;
    scanf("%d",&n);
    
    bool state=true;    //true=enter, false=leave
    for(i=0;i<2*n;i++){
        scanf("%d",&num);
        v.push_back(make_pair(num,state));
        state=!state;
    }

    //sort by time
    sort(v.begin(),v.end());

    //pure simulation
    int cnt=0, mymax=0;
    for(auto i:v){
        if(i.second){   //enter
            cnt++;
        }else{  //leave
            cnt--;
        }
        mymax=max(mymax,cnt);
    }
    printf("%d\n",mymax);
    return 0;
}