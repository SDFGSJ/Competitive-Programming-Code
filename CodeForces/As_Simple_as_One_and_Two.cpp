#include<bits/stdc++.h>
using namespace std;
void eliminate(string);
string str;
vector<int> ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t,i;
    cin>>t;
    while(t--){
        ans.clear();
        cin>>str;
        eliminate("twone"); //remove 'o',have to do this first
        eliminate("two");   //remove 'w'
        eliminate("one");   //remove 'n'
        cout<<ans.size()<<'\n';
        for(i=0;i<ans.size();i++){
            cout<<ans[i]+1<<' ';    //1-indexed
        }
        cout<<'\n';
    }
    return 0;
}
void eliminate(string pattern){
    int pos=0;  //try to find pattern starting from pos
    while(1){
        pos=str.find(pattern,pos);  //to avoid TLE
        if(pos!=string::npos){
            if(pattern=="twone"){
                ans.push_back(pos+2);
                str[pos+2]='x'; //don't erase,or the idx would mess up
                pos+=5; //move the position to the next word
            }else{
                ans.push_back(pos+1);
                str[pos+1]='x';
                pos+=3;
            }
        }else{
            break;
        }
    }
}