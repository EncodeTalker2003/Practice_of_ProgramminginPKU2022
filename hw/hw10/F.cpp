#include <iostream>
#include <set>
using namespace std;
// 在此处补充你的代码
class Rectangle{
    int a, b;

    public:
        friend class Comp;
        Rectangle(int _a, int _b): a(_a), b(_b) {}

        bool operator <(const Rectangle &p) const {
            if (a * b != p.a * p.b )return a * b > p.a * p.b;
            else return a + b > p.a + p.b;
        }

        friend ostream& operator << (ostream &os, const Rectangle &A) {
            os << A.a * A.b << " " << (A.a + A.b) * 2;
            return os;
        }

};

class Comp{
    public:

    bool operator() (const Rectangle &p, const Rectangle &q) const {
        if (p.a + p.b != q.a + q.b) return p.a + p.b < q.a + q.b;
        else return p.a * p.b < q.a * q.b;
    }
};

int main() {
    multiset<Rectangle> m1;
    multiset<Rectangle, Comp> m2;
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        m1.insert(Rectangle(a, b));
        m2.insert(Rectangle(a, b));
    }
    for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
        cout << *it << endl;
    }
	return 0;
}