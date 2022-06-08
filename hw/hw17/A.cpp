//この渇き、奪ってくれるか
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 100+50,M=10+5,K=(1<<5)+10;
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

struct node{
    int x,y,k,d,sta;
};
bool operator <(node p,node q) {
    return p.d>q.d;
}
priority_queue<node> q;
int n,m,dis[N][N][M][K],vis[N][N][M][K],tot,sx[K],sy[K],s[N][N];
string sq[N];
int dx[]={0,1,0,-1},dy[]={-1,0,1,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin>>n>>m) {
        if ((!n)&&(!m)) break;
        int x1,x2,y1,y2;
        rep(i,0,n-1) rep(j,0,n-1) s[i][j]=0;
        tot=0;
        rep(i,0,n-1) {
            cin>>sq[i];
            rep(j,0,n-1) {
                if (sq[i][j]=='K') {
                    x1=i;y1=j;
                } else if (sq[i][j]=='T') {
                    x2=i;y2=j;
                } else if (sq[i][j]=='S') {
                    sx[tot]=i;sy[tot]=j;
                    s[i][j]=tot;
                    tot++;
                }
            }
        }
        rep(i,0,n-1) rep(j,0,n-1) rep(k,0,m) rep(p,0,(1<<tot)-1) {
            dis[i][j][k][p]=maxd;
            vis[i][j][k][p]=0;
        }
        dis[x1][y1][0][0]=0;
        q.push((node){x1,y1,0,0,0});
        while (!q.empty()) {
            node pre=q.top();q.pop();
            if (vis[pre.x][pre.y][pre.k][pre.sta]) continue;
            vis[pre.x][pre.y][pre.k][pre.sta]=1;
            //cout<<"dis["<<pre.x<<" "<<pre.y<<" "<<pre.k<<" "<<pre.sta<<"]="<<pre.d<<endl;
            rep(i,0,3) {
                int nx=pre.x+dx[i],ny=pre.y+dy[i],nk=pre.k,nd=pre.d+1,ns=pre.sta;
                if ((nx<0)||(nx>=n)||(ny<0)||(ny>=n)||(sq[nx][ny]=='#')) continue;
                if (sq[nx][ny]=='S') {
                    int p=s[nx][ny];
                    if (((ns>>p)&1)==0) {
                        ns|=(1<<p);
                        nd++;
                    }
                } else if ((sq[nx][ny]>='0')&&(sq[nx][ny]<='9')) {
                    int p=sq[nx][ny]-'0';
                    if (p==nk+1) nk=p;
                }
                if (dis[nx][ny][nk][ns]>nd) {
                    dis[nx][ny][nk][ns]=nd;
                    if (!vis[nx][ny][nk][ns]) q.push((node){nx,ny,nk,nd,ns});
                }
            }
        }
        int ans=maxd;
        rep(s,0,(1<<tot)-1) ans=min(ans,dis[x2][y2][m][s]);
        if (ans==maxd) cout<<"impossible";
        else cout<<ans;
        cout<<endl;
    }

    return 0;
}