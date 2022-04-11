//我慢は要らない、壊し尽くす
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 200000 + 100;
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

list<int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    string op;
    list<int>::iterator it;
    while (T--) {
        cin >> op;
        if (op[0] == 'n') {
            int id; cin >> id;
        } else if (op[0] == 'a') {
            int id, num; cin >> id >> num;
            a[id].push_back(num);
            a[id].sort();
        } else if (op[0] == 'm') {
            int id1, id2; cin >> id1 >> id2;
            a[id1].merge(a[id2]);
            //a[id2].clear();
        } else if (op[0] == 'u') {
            int id; cin >> id;
            a[id].unique();
        } else if (op[0] == 'o') {
            int id; cin >> id;
            a[id].sort();
            for (it = a[id].begin(); it != a[id].end(); it++) {
                cout << (*it) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}