#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset 
{
	char a[bitNum/8+1];
	MyBitset() { memset(a,0,sizeof(a));};
	void Set(int i,int v) {
		char & c = a[i/8];
		int bp = i % 8;
		if( v ) 
			c |= (1 << bp);
		else 
			c &= ~(1 << bp);
	}
// 在此处补充你的代码
    class helper{
        int n;
        MyBitset *b;
        friend struct MyBitset;

        public:
            helper(int _n, MyBitset &_b){
                n = _n;
                b = &_b;
            }

            int getBit() const {
                return ((b->a[n / 8]) >> (n % 8)) & 1;
            }

            helper& operator= (int v) {
                b->Set(n, v);
                return *this;
            }

            helper& operator= (const helper &now) {
                int v = now.getBit();
                b->Set(n, v);
                return *this;
            }

            friend ostream& operator << (ostream &os, const helper& now) {
                os << now.getBit();
                return os;
            }
    }; 

    friend class helper;

    helper operator[] (int x) {
        return helper(x, *this);
    }

    void Print() {
		for(int i = 0;i < bitNum; ++i) 
			cout << (*this) [i];
		cout << endl;
	}

};

int main()
{
	int n;
	int i,j,k,v;
	while( cin >>  n) {
		MyBitset<20> bs;
		for(int i = 0;i < n; ++i) {
			int t;
			cin >> t;
			bs.Set(t,1);
		}
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		bs[i] = bs[j] = bs[k];
		bs.Print();
		cin >> i >> j >> k >> v;
		bs[k] = v;
		(bs[i] = bs[j]) = bs[k];
		bs.Print();
	}
	return 0;
}