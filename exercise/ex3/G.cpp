//この渇き、奪ってくれるか
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 2000 + 100;
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

int n,a[N],f[N][N],g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    a[0]=-1;
    int ans=0;
    rep(i,1,n) 
    {
        rep(j,0,i-1) {
            if (a[i]>a[j]) {
                f[i][j]=max(f[i][j],g[j]+a[i]);
                g[i]=max(g[i],f[i][j]);
            }
            ans=max(ans,f[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}