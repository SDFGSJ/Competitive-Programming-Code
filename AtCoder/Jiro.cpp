#include<bits/stdc++.h>
using namespace std;
int main(){
    char ab,ac,bc;
    scanf("%c %c %c",&ab,&ac,&bc);
    char ans;
    if(ab=='<' && ac=='<' && bc=='<'){  //a<b<c
        ans='B';
    }else if(ab=='<' && ac=='<' && bc=='>'){    //a<c<b
        ans='C';
    }else if(ab=='<' && ac=='>' && bc=='<'){    //impossible

    }else if(ab=='<' && ac=='>' && bc=='>'){    //c<a<b
        ans='A';
    }else if(ab=='>' && ac=='<' && bc=='<'){    //c>a>b
        ans='A';
    }else if(ab=='>' && ac=='<' && bc=='>'){    //impossible

    }else if(ab=='>' && ac=='>' && bc=='<'){    //a>c>b
        ans='C';
    }else if(ab=='>' && ac=='>' && bc=='>'){    //a>b>c
        ans='B';
    }
    printf("%c\n",ans);
    return 0;
}