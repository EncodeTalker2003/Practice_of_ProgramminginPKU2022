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

int n,m,k,a[110][110],vis[110][110];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};


void dfs(int x,int y) {
    if (vis[x][y]) return;
    vis[x][y]=1;
    rep(i,0,3) {
        int nx=x+dx[i],ny=y+dy[i];
        if ((nx<=0)||(nx>n)||(ny<=0)||(ny>m)) continue;
        if (abs(a[x][y]-a[nx][ny])>k) continue;
        dfs(nx,ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin>>n>>m>>k) {
        if (!n) break;
        rep(i,1,n) rep(j,1,m) cin>>a[i][j];
        rep(i,1,n) rep(j,1,m) vis[i][j]=0;
        int ans=0;
        rep(i,1,n) rep(j,1,m) {
            if (vis[i][j]) continue;
            ans++;dfs(i,j);
        }
        cout<<ans<<endl;
    }
    return 0;
}