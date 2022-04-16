#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
// 在此处补充你的代码
class Fib{
    int n;
    int a, b;
    public:

    Fib(int _n) {
        n = _n;
        a = b = 1;
    }

    bool operator !=(Fib b) {
        return n != b.n;
    }
    
    void operator ++() {
        int c = a + b;
        a = b; b = c;
        n++;
    }

    int operator *() {
        return a;
    }
};

int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;
		
	    Fib f1(1), f2(n);
	    ostream_iterator<int> it(cout, " ");
	    Copy(f1, f2, it);
	    cout << endl;
	}
	return 0;
}