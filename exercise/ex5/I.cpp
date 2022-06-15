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

int n,m,k,dis[110][110][12],vis[110][110][12];
struct node{int x,y,t;};
queue<node> q;
string s[110];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        cin>>n>>m>>k;
        int sx,sy,ex,ey;
        rep(i,0,n-1) {
            cin>>s[i];
            rep(j,0,m-1) {
                if (s[i][j]=='S') {sx=i;sy=j;}
                else if (s[i][j]=='E') {ex=i;ey=j;}
            }
        }
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[sx][sy][0]=0;
        vis[sx][sy][0]=1;
        q.push((node){sx,sy,0});
        while (!q.empty()) {
            node pre=q.front();q.pop();
            rep(i,0,3) {
                node now=pre;
                now.x+=dx[i];now.y+=dy[i];now.t=(now.t+1)%k;
                if ((now.x<0)||(now.x>=n)||(now.y<0)||(now.y>=m)) continue;
                if ((s[now.x][now.y]=='#')&&(now.t)) continue;
                if (!vis[now.x][now.y][now.t]) {
                    dis[now.x][now.y][now.t]=dis[pre.x][pre.y][pre.t]+1;
                    vis[now.x][now.y][now.t]=1;
                    q.push(now);
                }
            }
        }
        int ans=1e9;
        rep(i,0,k-1) ans=min(ans,dis[ex][ey][i]);
        if (ans==1e9) cout<<"Oop!"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}