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
set<pii> s;
set<pii>::iterator it;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    s.insert(mkp(1000000000, 1));
    cin >> n;
    rep(i, 1, n) {
        pii now;
        cin >> now.sec >> now.fir;
        pii ans;
        ans.fir = 1000000010;
        it = s.lower_bound(now);
        if (it != s.begin()) {
            it--;
            ans.fir = now.fir - (*it).fir;
            ans.sec = (*it).sec;
        }
        it = s.upper_bound(now);
        if ((it != s.end()) && ((*it).fir - now.fir < ans.fir)) {
            ans.fir = (*it).fir - now.fir;
            ans.sec = (*it).sec;
        }
        cout << now.sec << " " << ans.sec << endl;
        s.insert(now);
    }
    return 0;
} 