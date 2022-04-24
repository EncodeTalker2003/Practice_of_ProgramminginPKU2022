#include<iostream>
using namespace std;
unsigned int calc(unsigned int n,unsigned m,int x,int y) {
// 在此处补充你的代码
    for (int i = 0; i < x; i++) {
        if ((m >> i) & 1) m ^= (1 << i);
        if ((n >> i) & 1) m ^= (1 << i);
    }
    //cout << m << endl;
    for (int i = 31; i > 31 - y; i--) {
        if ((m >> i) & 1) m ^= (1 << i);
        if ((n >> i) & 1) m ^= (1 << i);
    }
    return m;
}
int main() {
  int x, y, t;
  unsigned int n, m;
  cin >> t;
  while (t--) { 
    cin >> n >> m >> x >> y;
    cout << calc(n, m, x, y) << endl;
  }
  return 0;
}