#include<bits/stdc++.h>
using namespace std;
char s[100010];
deque<char> dq;
int main(){
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        dq.emplace_back(s[i]);
    }

    int cnt=0;
    while(dq.size()>=2){    //need to check the char at the front and back, so the size should be at least 2
        if(dq.front()==dq.back()){
            dq.pop_front();dq.pop_back();
        }else{
            if(dq.front()=='x'){
                cnt++;  //add 'x' at the back
                dq.pop_front();
            }else if(dq.back()=='x'){
                cnt++;  //add 'x' at the front
                dq.pop_back();
            }else{
                cnt=-1; //cant be a palindrome
                break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
/*
deque
since there is only add operation, we can simulate it using deque
no need to add 1 to cnt if there remains a char after the while loop terminates
*/