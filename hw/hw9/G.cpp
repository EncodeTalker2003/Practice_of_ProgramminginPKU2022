//我慢は要らない、壊し尽くす
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 10000000 + 100;
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

int tot, pri[N], num[N];
bool nopri[N];

void sieve(int n) {
    num[1] = 0;
    rep(i, 2, n) {
        if (!nopri[i]) {
            pri[++tot] = i; num[i] = 0;
        }
        for (int j = 1; j <= tot && i * pri[j] <= n; j++) {
            nopri[i * pri[j]] = 1;
            num[i * pri[j]] = num[i];
            if (!num[i]) num[i * pri[j]] = 1;
            if (i % pri[j] == 0) break; 
            num[i * pri[j]]++;
        }
    }
}

class myLess{
    public:
    bool operator() (const int& a, const int& b) const {
        if (num[a] != num[b]) return num[a] < num[b];
        else return a < b;
    }
};

multiset<int, myLess> s;
multiset<int, myLess>::iterator it;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve(10000000);
    int T; cin >> T;
    while (T--) {
        rep(i, 1, 10) {
            int x; cin >> x;
            s.insert(x);
        }
        it = s.end(); it--;
        cout << *it << " " << *(s.begin()) << endl;
        s.erase(it); s.erase(s.begin());
    }
    return 0;
}