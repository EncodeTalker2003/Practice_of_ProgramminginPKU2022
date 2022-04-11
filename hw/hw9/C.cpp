//我慢は要らない、壊し尽くす
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 100000 + 100;
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

set<int> add;
multiset<int> s;
multiset<int>::iterator it;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    string op;
    while (T--) {
        int x;
        cin >> op >> x;
        if (op == "add") {
            s.insert(x);
            add.insert(x);
            cout << s.count(x) << endl;
        } else if (op == "ask") {
            if (add.find(x) != add.end()) cout << 1; 
            else cout << 0;
            cout << ' ';
            cout << s.count(x) << endl;
        } else if (op == "del") {
            cout << s.count(x) << endl;
            it = s.find(x);
            if (it != s.end()) s.erase(x);
        }
    }
    return 0;
}
