#include <iostream>
using namespace std;
class Complex{
    int a, b;
    public:

    Complex(int _a = 0, int _b = 0): a(_a), b(_b) {}
    Complex(const char* str) {
        a = str[0] - '0';
        b = str[2] - '0';
    }
    Complex(Complex &p) {
        a = p.a; b = p.b;
    }

    friend ostream& operator << (ostream& os, const Complex& p) {
        int fir = 0;
        if (p.a) {
            fir = 1;
            os << p.a;
        }
        if (p.b) {
            if ((fir) && (p.b > 0)) os << "+";
            os << p.b << "i";
            fir = 1;
        }
        if (!fir) os << "0";
        return os;
    }

    friend Complex operator +(Complex &p, Complex &q) {
        Complex ans;
        ans.a = p.a + q.a;
        ans.b = p.b + q.b;
        return ans;
    }

    friend Complex operator -(Complex &p, Complex &q) {
        Complex ans;
        ans.a = p.a - q.a;
        ans.b = p.b - q.b;
        return ans;
    }

    friend Complex operator *(Complex &p, Complex &q) {
        Complex ans;
        ans.a = p.a * q.a - p.b * q.b;
        ans.b = p.a * q.b + p.b * q.a;
        return ans;
    }

    Complex& operator +=(Complex &p) {
        a += p.a;
        b += p.b;
        return *this;
    }

    Complex& operator -=(int p) {
        a -= p;
        return *this;
    }

    Complex& operator *=(Complex p) {
        int tmpa = a, tmpb = b;
        a = tmpa * p.a - tmpb * p.b;
        b = tmpa * p.b + tmpb * p.a;
        return *this;
    }
};

int main() {
	Complex c1;
	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
	Complex c3(c2);
	Complex c4(-15);
	cout << c2 << endl;
	cout << c3 << endl;
	cout << c4 << endl;
	cout << c2 + c4 << endl;
	cout << c2 - c3 << endl;
	cout << c2 * c3 << endl;
	c2 += c4;
	cout << c2 << endl;
	c2 -= -12;
	cout << c2 << endl;
	c3 *= c3;
	cout << c3 << endl;
	return 0;
}