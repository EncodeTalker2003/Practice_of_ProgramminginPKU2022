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

int n,m,s,g[1100],f[2][2100][1100];
int l[1100],h[1100],c[1100],t[1100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("a.out","w",stdout);
    cin>>m>>n>>s;
    rep(i,1,n) {
        cin>>h[i]>>c[i]>>t[i];
        string s;cin>>s;
        l[i]=(s[0]=='l');
    }
    int mxh=min(m*24,((s-1)/100+1)*36);
    //cout<<mxh<<endl;
    memset(g,0x3f,sizeof(g));g[0]=0;
    rep(i,1,mxh) {
        int p=max(0,i-24);g[i]=min(g[i],g[p]+100);
        p=max(0,i-48);g[i]=min(g[i],g[p]+150);
        p=max(0,i-72);g[i]=min(g[i],g[p]+200);
    }
    int pre=0,now=1;
    memset(f[0],-0x3f,sizeof(f[0]));
    f[0][0][0]=0;
    rep(i,1,n) {
        rep(j,0,mxh) rep(k,0,s) f[now][j][k]=f[pre][j][k];
        if (l[i]) {
            per(j,mxh,t[i]) per(k,s,c[i]) f[now][j][k]=max(f[now][j][k],f[now][j-t[i]][k-c[i]]+h[i]);
        } else {
            rep(j,t[i],mxh) rep(k,c[i],s) f[now][j][k]=max(f[now][j][k],f[now][j-t[i]][k-c[i]]+h[i]);
        }
        now^=1;pre^=1;
        
    }
    int ans=0;
    rep(j,0,mxh) rep(k,0,s) {
        if (k+g[j]>s) continue;
        ans=max(ans,f[pre][j][k]);
    }
    cout<<ans<<endl;
    return 0;
}
