#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);

    /*
    a: #strings that ends with A
    ba: #strings that start with B and ends with A
    b: #strings that start with B
    ab: #occurrence of AB
    */
    int a=0,ba=0,b=0,ab=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s.front()!='B' && s.back()=='A'){
            a++;
        }else if(s.front()=='B' && s.back()!='A'){
            b++;
        }else if(s.front()=='B' && s.back()=='A'){
            ba++;
        }
        for(int j=0;j+1<s.length();j++){
            if(s[j]=='A' && s[j+1]=='B'){
                ab++;
            }
        }
    }

    int ans=ab+max(ba-1,0); //concat all ba's with each other
    if(ba>0 && a>0){    //concat 1 a to start of ba
        ans++;
        a--;
    }
    if(ba>0 && b>0){    //concat 1 b to end of ba
        ans++;
        b--;
    }
    ans+=min(a,b);  //conat rest of a,b
    printf("%d\n",ans);
    return 0;
}