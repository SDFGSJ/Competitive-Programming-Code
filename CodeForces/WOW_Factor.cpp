#include<bits/stdc++.h>
using namespace std;
char tmp[1000010];
int main(){
    int i,j;
    vector<int> v,o;    //record the continous count of 'v','o'
    string s;   //parse the tmp,only remove 1 'v' in tmp
    scanf("%s",tmp);
    
    //parsing
    for(i=0;tmp[i]!='\0';){
        if(tmp[i]=='v'){
            for(j=i;tmp[j]=='v';j++){
                s.push_back(tmp[j]);
            }
            if(j-i>=2){
                v.push_back(j-i-1);
            }else{  //only 1 'v'
                s.pop_back();
            }
            i=j;
        }else{
            s.push_back(tmp[i]);
            i++;
        }
    }
    
    //ignore the prefix 'o',since it won't make wow
    for(i=0;s[i]=='o';i++){

    }

    //count the number of consecutive 'o'
    while(s[i]!='\0'){
        if(s[i]=='v'){
            i++;
        }else{
            for(j=i;s[j]=='o';j++){

            }
            o.push_back(j-i);
            i=j;
        }
    }

    int total=0;    //the sum of vector v
    total=accumulate(v.begin(),v.end(),total);

    long long ans=0;    //beware of overflow
    if(v.size()==0){    //special case
        printf("0");
        return 0;
    }

    int front_sum=v[0];
    for(i=0;i<v.size()-1;i++){
        ans += (long long)front_sum * (long long)(total - front_sum) * (long long)o[i];
        front_sum+=v[i+1];
    }
    printf("%lld\n",ans);
    return 0;
}