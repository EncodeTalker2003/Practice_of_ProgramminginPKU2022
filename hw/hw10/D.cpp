#include <iostream>
using namespace std;

class A {
public:
// 在此处补充你的代码
    int n;
    A(int _n): n(_n) {}

    friend ostream& operator << (ostream& os, A& a) {
        os << a.n;
        return os;
    }

    int& getValue() {
        return n;
    }

    operator int() {
        return n;
    }

    int& operator +=(int x) {
        n += x;
        return n;
    }

    int& operator -=(int x) {
        n -= x;
        return n;
    }
};

int main() {
	int t;
	cin >> t;
	while(t-- ) {
		int m,n,k;
		cin >> m >> n >> k;	
	    A a(m);
	    A b = a;
	    cout << b << endl;
	    cout << (a += b -= n) << endl;
	    cout << a.getValue() << endl;
	    a.getValue() = k;
	    cout << a << endl;
	} 
	return 0;
}