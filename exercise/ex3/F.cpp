//この渇き、奪ってくれるか
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

int n;
ll f[40];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    f[0]=1;f[2]=3;
    rep(i,4,30) {
        f[i]=f[i-2]*3;
        rep(j,0,i-4) {
            if (j&1) continue;
            f[i]+=f[j]*2;
        }
    }
    while (cin>>n) {
        if (n==-1) break;
        if (n&1) cout<<0<<endl;
        else cout<<f[n]<<endl;
    }
    return 0;
}