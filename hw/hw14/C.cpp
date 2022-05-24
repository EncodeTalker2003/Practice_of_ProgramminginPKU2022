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

int n,a[N],f[N],g[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) {
            f[i]=1;
            rep(j,1,i-1) if (a[i]>a[j]) f[i]=max(f[i],f[j]+1);
        }
        per(i,n,1) {
            g[i]=1;
            rep(j,i+1,n) if (a[i]>a[j]) g[i]=max(g[i],g[j]+1);
        }
        int ans=0;
        rep(i,1,n) ans=max(ans,max(f[i],g[i]));
        cout<<ans<<endl;
    }
}