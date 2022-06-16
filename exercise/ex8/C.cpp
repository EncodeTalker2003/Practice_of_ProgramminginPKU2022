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

int n,m,dis[20][20],vis[20][20];
string s[20];
queue<pii> q;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        cin>>n>>m;
        int sx=0,sy,ex,ey;
        rep(i,0,n-1) {
            cin>>s[i];
            rep(j,0,n-1) {
                if (s[i][j]=='S') {sx=i;sy=j;}
                else if (s[i][j]=='E') {ex=i;ey=j;}
            }
        }
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[sx][sy]=0;vis[sx][sy]=1;
        q.push(mkp(sx,sy));
        while (!q.empty()) {
            pii pre=q.front();q.pop();
            rep(i,0,3) {
                int nx=pre.fir+dx[i],ny=pre.sec+dy[i];
                if ((nx<0)||(nx>=n)||(ny<0)||(ny>=n)||(s[nx][ny]=='#')) continue;
                if (!vis[nx][ny]) {
                    dis[nx][ny]=dis[pre.fir][pre.sec]+1;
                    vis[nx][ny]=1;
                    q.push(mkp(nx,ny));
                }
            }
        }
        if (dis[ex][ey]>m) cout<<"NO";
        else cout<<"YES";
        cout<<endl;
    }
    return 0;
}