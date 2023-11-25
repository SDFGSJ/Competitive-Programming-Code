#include<bits/stdc++.h>
using namespace std;
int a[10][10];
bool row[9][10], col[9][10];
bool subgrids[3][3][10];
bool illegal(int r, int c, int num) {
    return row[r][num] || col[c][num] || subgrids[r / 3][c / 3][num];
}
void update(int r, int c, int num, bool val) {
    row[r][num] = val;
    col[c][num] = val;
    subgrids[r / 3][c / 3][num] = val;
}
bool check() {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (illegal(r, c, a[r][c]))
                return false;
            update(r, c, a[r][c], true);
        }
    }
    return true;
}
int main() {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&a[i][j]);
        }
    }
    cout << (check() ? "Yes\n" : "No\n");
    return 0;
}