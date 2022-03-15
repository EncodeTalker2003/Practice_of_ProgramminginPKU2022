#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
int num[110];
	int len;

	public:

	
	CHugeInt (const char* s) {
		memset(num, 0, sizeof(num));
		len = strlen(s);
		for (int i = 0; i < len; i++) {
			num[i] = s[len - i - 1] - '0';
		}
	}

	CHugeInt (int x) {
		memset(num, 0, sizeof(num));
		len = 0;
		while (x) {
			num[len] = x % 10;
			x /= 10;
			len++;
		}
	}

	CHugeInt(const CHugeInt &a) {
		memset(num, 0, sizeof(num));
		this->len = a.len;
		for (int i = 0; i < a.len; i++) {
			this->num[i] = a.num[i];
		}
	}


	friend ostream& operator << (ostream& os,const CHugeInt& a) {
		if (a.len == 0) os << 0;
		else {
			for (int i = a.len - 1; i >= 0; i--) {
				os << a.num[i];
			}
			//os << 'a' << endl;
		}
		return os;
	}

	friend CHugeInt operator + (const CHugeInt& a, const CHugeInt& b) {
		CHugeInt c(a);
		c.len = max(a.len, b.len);
		for (int i = 0; i < c.len; i++) {
			c.num[i] += b.num[i];
			if (c.num[i] > 9) {
				c.num[i] -= 10;
				c.num[i + 1] ++;
			}
		}
		if (c.num[c.len]) c.len++;
		return c;
	}

	CHugeInt operator +=(int x) {
		CHugeInt a(*this), b(x);
		*this = a + b;
		return *this;
	}

	friend CHugeInt operator +(const CHugeInt& a, const int x) {
		CHugeInt b = x;
		return a + b;
	}

	friend CHugeInt operator +(const int x, const CHugeInt& a) {
		CHugeInt b = x;
		return a + b;
	}

	CHugeInt& operator ++() {
		this->num[0]++;
		int tp = 0;
		while (this->num[tp] > 9) {
			this->num[tp] -= 10;
			tp++;
			this->num[tp]++;
		}
		this->len = max(this->len, tp + 1);
		//cout << this->num[0] << endl;
		return *this;
	}

	CHugeInt operator ++(int x) {
		CHugeInt pre(*this);
		this->num[0]++;
		int tp = 0;
		while (this->num[tp] > 9) {
			this->num[tp] -= 10;
			tp++;
			this->num[tp]++;
		}
		this->len = max(this->len, tp + 1);
		//cout << this->num[0] << endl;
		return pre;
	}

};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}