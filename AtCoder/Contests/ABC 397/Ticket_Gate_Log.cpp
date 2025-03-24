#include<bits/stdc++.h>
using namespace std;
char s[105];
deque<char> dq;
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        dq.emplace_back(s[i]);
    }

    int ans=0;
    while(dq.size()>=2){
        char c1=dq[0],c2=dq[1];
        if(c1=='i' && c2=='o'){
            dq.pop_front();
            dq.pop_front();
            continue;
        }
        dq.pop_front();
        ans++;
    }
    if(dq.size()){
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
/*
deque
pop 2 characters from the front of deque and check whether they are ('i','o')
if they are "io", remove these 2 chars
if not, we only take 1 char from the front
    if we get 'i', we put an 'o' after it => ans++
    if we get 'o', we put an 'i' in front of it => ans++
if there's any char remains in the deque, we need to add another matching char for it => ans++
*/