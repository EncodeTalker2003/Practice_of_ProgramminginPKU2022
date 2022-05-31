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

namespace My_Math{
    #define N 100000

    int fac[N+100],invfac[N+100];

    int add(int x,int y) {return x+y>=maxd?x+y-maxd:x+y;}
    int dec(int x,int y) {return x<y?x-y+maxd:x-y;}
    int mul(int x,int y) {return 1ll*x*y%maxd;}
    ll qpow(ll x,int y)
    {
        ll ans=1;
        while (y)
        {
            if (y&1) ans=mul(ans,x);
            x=mul(x,x);y>>=1;
        }
        return ans;
    }
    int getinv(int x) {return qpow(x,maxd-2);}

    int C(int n,int m)
    {
        if ((n<m) || (n<0) || (m<0)) return 0;
        return mul(mul(fac[n],invfac[m]),invfac[n-m]);
    }

    void math_init()
    {
        fac[0]=invfac[0]=1;
        rep(i,1,N) fac[i]=mul(fac[i-1],i);
        invfac[N]=getinv(fac[N]);
        per(i,N-1,1) invfac[i]=mul(invfac[i+1],i+1);
    }
    #undef N
}
using namespace My_Math;

int n,a[N],f[N],g[N],m;
vi ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    f[0]=1;
    rep(i,1,n) {
        per(j,m-a[i],0) f[j+a[i]]=add(f[j+a[i]],f[j]);
    }
    //rep(i,0,m) cout<<f[i]<<" ";cout<<endl;
    rep(i,1,n) {
        rep(j,0,m) g[j]=f[j];
        rep(j,0,m-a[i]) g[j+a[i]]=dec(g[j+a[i]],g[j]);
        //rep(j,0,m) cout<<g[j]<<" ";cout<<endl;
        if (!g[m]) ans.pb(a[i]);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (auto x:ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}

