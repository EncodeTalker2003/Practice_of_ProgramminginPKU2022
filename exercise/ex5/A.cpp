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

int n,a[10][10],b[10],ans;

void chk() {
    rep(i,0,3) {
        b[i]=0;
        rep(j,0,3) b[i]+=a[i][j];
    }
    int cnt=1;
    rep(i,1,3) cnt+=(b[0]<b[i]);
    ans=min(ans,cnt);
}

void dfs(int x,int y) {
    if ((x==3)&&(y==4)) {
        chk();
        return;
    }
    //cout<<x<<" "<<y<<endl;
    int nx=x,ny=y+1;
    if (ny>3) {
        nx++;ny=nx+1;
    }
    if (a[x][y]==-1) {
        a[x][y]=1;a[y][x]=0;
        dfs(nx,ny);
        a[x][y]=0;a[y][x]=1;
        dfs(nx,ny);
        a[x][y]=a[y][x]=-1;
    } else dfs(nx,ny);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        rep(i,0,3) rep(j,0,3) a[i][j]=0;
        rep(i,0,3) {
            string s;
            cin>>s;
            rep(j,0,3) {
                if (s[j]=='W') a[i][j]=1;
                else if (s[j]=='L') a[i][j]=0;
                else if (s[j]=='?') a[i][j]=-1;
            }
        }
        ans=4;
        dfs(0,1);
        cout<<ans<<endl;
    }
    return 0;
}