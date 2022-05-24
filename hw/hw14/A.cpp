//この渇き、奪ってくれるか
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 100 + 100;
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

int n,m,a[N][N],f[N][N];
pii p[N*N];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

bool cmp(pii x,pii y) {
    return a[x.fir][x.sec]>a[y.fir][y.sec];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n) rep(j,1,m) {
        cin>>a[i][j];
        p[(i-1)*m+j]=mkp(i,j);
    }
    sort(p+1,p+1+n*m,cmp);
    rep(i,1,n*m) {
        int x=p[i].fir,y=p[i].sec;
        f[x][y]=1;
        //cout<<x<<" "<<y<<endl;
        rep(d,0,3) {
            int nx=x+dx[d],ny=y+dy[d];
            if ((nx<1)||(nx>n)||(ny<1)||(ny>m)||(a[nx][ny]<=a[x][y])) continue;
            f[x][y]=max(f[x][y],f[nx][ny]+1);
        }
    }
    int ans=0;
    rep(i,1,n) rep(j,1,m) ans=max(ans,f[i][j]);
    cout<<ans<<endl;
    return 0;
}