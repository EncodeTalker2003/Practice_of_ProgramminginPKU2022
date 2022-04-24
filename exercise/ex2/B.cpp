#include <cstdio>
#include <iostream>
using namespace std;

class f {
// 在此处补充你的代码
    int n,m;
    public:
        f(int _n, int _m = 0): n(_n), m(_m) {}
        operator int() {
            return m * n;
        }

        int operator() (int x) {
            return x - n;
        }
};

int main() {
  cout << f(3)(5) << endl;
  cout << f(4)(10) << endl;
  cout << f(114)(514) << endl;
  cout << f(9,7) << endl;
  cout << f(2,3) << endl;
  cout << f(2,5) << endl;
}