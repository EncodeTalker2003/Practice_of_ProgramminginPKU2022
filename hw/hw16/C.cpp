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

int n,sq[20][20],f[N][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,0,n-1) rep(j,0,n-1) cin>>sq[i][j];
    memset(f,0x3f,sizeof(f));
    f[1][0]=0;
    rep(pre,0,(1<<n)) rep(i,0,n-1) {
        if ((pre>>i)&1) continue;
        int sta=pre^(1<<i);
        rep(j,0,n-1) if ((pre>>j)&1) {
            f[sta][i]=min(f[sta][i],f[pre][j]+sq[j][i]);
        }
    }
    cout<<f[(1<<n)-1][n-1]<<endl;
    return 0;
}