//近寄るな、嘘はもうたくさんだ
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
#define go(u,i) for (register int i = head[u], v = sq[i].to; i; i = sq[i].nxt, v=sq[i].to)
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8

string warrior[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int hp[5];

class headquarter{
    public:
        int totM, tim, allCnt;
        int ord[5], cnt[5], warriorPos = 0;
        string name;
        bool can;
    
        headquarter(int m,int op) {
            totM = m;
            tim = -1;
            can = 1;
            allCnt = 0;
            warriorPos = 4;
            memset(cnt, 0, sizeof(cnt));
            if (op == 0) {
                ord[0] = 2; ord[1] = 3; ord[2] = 4; ord[3] = 1; ord[4] = 0;
                name = "red";
            }
            else {
                ord[0] = 3; ord[1] = 0; ord[2] = 1; ord[3] = 2; ord[4] = 4;
                name = "blue";
            }
        }

        void out(int nowId) {
            totM -= hp[nowId];
            cnt[nowId]++; allCnt++;
            cout << setfill('0') << setw(3) << tim << ' ' << name << ' ';
            cout << warrior[nowId] << " " << allCnt << " born with strength " << hp[nowId] << ',';
            cout << cnt[nowId] << ' ' << warrior[nowId] << " in " <<  name << " headquarter" << endl;
        }

        void endOut() {
            can = 0;
            cout << setfill('0') << setw(3) << tim << ' ' << name << ' ';
            cout << "headquarter stops making warriors" << endl;
        }

        void produce() {
            if (!can) return;
            tim++;
            rep(i, 0, 4) {
                warriorPos++;
                if (warriorPos == 5) {
                    warriorPos = 0;
                }
                if (totM >= hp[ord[warriorPos]]) {
                    out(ord[warriorPos]);
                    return;
                }
                
            }
            endOut();
        }
};

int main() {
    ios::sync_with_stdio(false);
    //freopen("a.out", "w", stdout);
    int T;
    cin >> T;
    rep(cas, 1, T) {
        cout << "Case:" << cas << endl;
        int m;
        cin >> m;
        rep(i, 0, 4) cin >> hp[i];
        headquarter rh = headquarter(m, 0);
        headquarter bh = headquarter(m, 1);
        while ((rh.can) || (bh.can)) {
            rh.produce();
            bh.produce();
        }
    }
    return 0;
}
