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

int n,m,k,a[N][N],vis[N];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int ans;

void dfs(int x,int y,int now) {
    ans=max(ans,now);
    vis[a[x][y]]=1;
    rep(i,0,3) {
        int nx=x+dx[i],ny=y+dy[i];
        if ((nx<=0)||(nx>n)||(ny<=0)||(ny>m)||(vis[a[nx][ny]])) continue;
        dfs(nx,ny,now+1);
    }
    vis[a[x][y]]=0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n) rep(j,1,m) cin>>a[i][j];
    dfs(1,1,1);
    cout<<ans<<endl;
    return 0;
}