#include<bits/stdc++.h>
using namespace std;
int main(){
    int len,i;
    char s[20];
    vector<int> ans;
    scanf("%d%s",&len,s);

    for(i=0;i<len;i++){
        if(s[i]!='0' && s[i]!='1'){ //cant put 0,1 into ans
            if(s[i]=='4'){  //4! = 3! * 2 * 2 = 3! * 2! * 2!
                ans.push_back(3);
                ans.push_back(2);ans.push_back(2);
            }else if(s[i]=='6'){    //6! = 5! * 2 * 3 = 5! * 3!
                ans.push_back(5);
                ans.push_back(3);
            }else if(s[i]=='8'){    //8! = 7! * 2 * 2 * 2 = 7! * 2! * 2! * 2!
                ans.push_back(7);
                ans.push_back(2);ans.push_back(2);ans.push_back(2);
            }else if(s[i]=='9'){    //9! = 7! * 2^3 * 3^2 = 7! * 3! * 3! * 2!
                ans.push_back(7);
                ans.push_back(3);ans.push_back(3);
                ans.push_back(2);
            }else{
                ans.push_back(s[i]-'0');
            }
        }
    }

    sort(ans.begin(),ans.end(),greater<int>());
    for(i=0;i<ans.size();i++){
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}