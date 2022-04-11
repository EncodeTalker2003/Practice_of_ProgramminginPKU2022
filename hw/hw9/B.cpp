//我慢は要らない、壊し尽くす
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 1000000 + 100;
const db pi = acos(-1.0);
#define lowbit(x) ((x) & (-x))
#define sqr(x) (x) * (x)
#define rep(i,a,b) for (int i = a; i <= b;i++)
#define per(i,a,b) for (int i = a; i >= b;i--)
#define go(x,a) for (auto &x: a)
#define trav(u,i,sq) for (register int i = head[u], v = sq[i].to; i; i = sq[i].nxt, v=sq[i].to)
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8

multiset<double> s;
multiset<double>::iterator it;
int n, tp = 0;
stack<double> sta;
string str;

int main() {
    scanf("%d", &n);
    rep(i, 1, n) {
        double x; cin >> x;
        s.insert(x);
    }
    while (cin >> str) {
        if (str == "=") {
            double ans = sta.top(); sta.pop();
            printf("%e\n", ans);
            it = s.begin();
            s.erase(it);
            s.insert(ans);
        } else if ((str == "+") || (str == "-") || (str == "*") || (str == "/") || (str == "^")) {
            double x = sta.top(); sta.pop();
            double y = sta.top(); sta.pop();
            if (str[0] == '+') y += x;
            else if (str[0] == '-') y -= x;
            else if (str[0] == '*') y *= x;
            else if (str[0] == '/') y /= x;
            else if (str[0] == '^') y = pow(y, x);
            sta.push(y);
        } else {
            sta.push(atof(str.c_str()));
        }
    }
    puts("");
    int tmp = 0;
    for (it = s.begin(); it != s.end(); it++) {
        printf("%e", *it);
        if (tmp < 9) {
            putchar(' ');
            tmp++;
        } else {
            puts("");
            tmp = 0;
        }
    }
    return 0;
}
/*
12
1e6 1e-6 0.001 1000 1e6 1e-6 0.001 1000 1e6 1e-6 0.001 1000
1 2 + 3 4 + * =
1 0.1 / 8 ^ =
*/
