#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int main(){
    int n,i,j;
    cin>>n;

    v.push_back("0");
    v.push_back("1");
    for(i=2;i<(1<<n);i<<=1){
        //push back the reverse of v
        for(j=i-1;j>=0;j--){
            v.push_back(v[j]);
        }

        //append '0' to the first half
        for(j=0;j<i;j++){
            v[j]="0"+v[j];
        }

        //append '1' to the second half
        for(j=i;j<2*i;j++){
            v[j]="1"+v[j];
        }
    }
    for(auto i:v){
        cout<<i<<'\n';
    }
    return 0;
}
//refers to geeks for geeks