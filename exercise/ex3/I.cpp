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

int n,a[N],pre[N],suf[N],f[N],g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        int mn=1e9;
        rep(i,1,n) {
            mn=min(mn,a[i]);
            f[i]=a[i]-mn;
        }
        int mx=-1e9;
        per(i,n,1) {
            mx=max(mx,a[i]);
            g[i]=mx-a[i];
        }
        pre[0]=suf[n+1]=0;
        rep(i,1,n) pre[i]=max(pre[i-1],f[i]);
        per(i,n,1) suf[i]=max(suf[i+1],g[i]);
        int ans=0;
        rep(i,1,n) ans=max(ans,pre[i]+suf[i]);
        cout<<ans<<endl;
    }
    return 0;
}