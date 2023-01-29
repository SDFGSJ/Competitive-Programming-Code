#include <iostream>
using namespace std;
 
int main() {
  int n, k;
  cin >> n >> k;
  int l = 1, r = n;
  while (r > l) {
    int m = (r + l)/2;
    int lin = 0;
    for (int i = m; i > 0; i /= k) {
      lin += i;
    }
    if (lin >= n) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }
  cout << l << endl;
  return 0;
}