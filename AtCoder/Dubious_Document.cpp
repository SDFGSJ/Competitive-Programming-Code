#include<bits/stdc++.h>
using namespace std;
char s[55];
int distri[55][30]; //distri[i][j] = # of char 'a'+j in s[i]
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        for(int j=0;s[j]!='\0';j++){
            distri[i][s[j]-'a']++;
        }
    }

    for(int i=0;i<26;i++){
        int mymin=INT_MAX;
        for(int j=0;j<n;j++){
            mymin=min(mymin,distri[j][i]);
        }
        for(int j=0;j<mymin;j++){
            printf("%c",'a'+i);
        }
    }
    printf("\n");
    return 0;
}
/*
record the alphabet distribution of every string
take the min of every char
*/