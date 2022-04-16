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

map<string, int> mp[N];
map<string, int> nameId;
int now[N], m;
string a[N][10];

void work(int id, string str) {
    if (now[id] < 6) {
        a[id][++now[id]] = str;
    } else {
        mp[id][a[id][1]]++;
        rep(i, 2, 6) a[id][i - 1] = a[id][i];
        a[id][6] = str;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n; m = 0;
        nameId.clear();
        while (n--) {
            string op, nam, str;
            cin >> op >> nam >> str;
            int id;
            if ((nameId.count(nam)) && (nameId[nam] > 0)) id = nameId[nam];
            else {
                nameId[nam] = (++m);
                id = m;
            }
            if (op[0] == 'C') {
                work(id, str);
            } else if (op[0] == 'T') {
                if ((mp[id].count(str)) && (mp[id][str] > 0)) {
                    mp[id][str]--;
                    work(id, str);
                    cout << "Success" << endl;
                } else {
                    cout << "Failed" << endl;
                }
            }
        }
        rep(i, 1, m) {now[i] = 0; mp[i].clear();}
    }
    return 0;
}
                    
