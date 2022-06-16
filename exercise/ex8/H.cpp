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

struct hnode{
    int x,y,k,op,d;
};

bool operator <(hnode p,hnode q) {return p.d>q.d;}
priority_queue<hnode> q;
int n,m,k,dis[110][110][12][5];
bool vis[110][110][12][5];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
string s[110];

void jump(int x,int y,int k,int op,int d) {
    //cout<<"start "<<x<<" "<<y<<endl;
    rep(i,1,k) {
        x+=dx[op];y+=dy[op];
        if ((x<0)||(x>=n)||(y<0)||(y>=m)) break;
        //cout<<"jump "<<x<<" "<<y<<" "<<i<<" "<<d<<endl;
        int now=i;
        int nx=x+dx[op],ny=y+dy[op];
        if ((nx<0)||(nx>=n)||(ny<0)||(ny>=m)) now=k;
        if ((s[x][y]!='#')&&(dis[x][y][now][op]>d)) {
            dis[x][y][now][op]=d;
            q.push((hnode){x,y,now,op,d});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cas=0;
    while(cin>>n>>m>>k) {
        if ((n==0)&&(m==0)&&(k==0)) break;cas++;
        int sx=0,sy,ex,ey;
        rep(i,0,n-1) {
            cin>>s[i];
            rep(j,0,m-1) {
                if (s[i][j]=='S') {sx=i;sy=j;}
                else if (s[i][j]=='T') {ex=i;ey=j;}
            }
        }
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[sx][sy][k][4]=0;
        q.push((hnode){sx,sy,k,4,0});
        while (!q.empty()) {
            hnode pre=q.top();q.pop();
            if (vis[pre.x][pre.y][pre.k][pre.op]) continue;
            //cout<<pre.x<<" "<<pre.y<<" "<<pre.k<<" "<<pre.d<<endl;
            if ((s[pre.x][pre.y]=='E') && (pre.op<4)) jump(pre.x,pre.y,pre.k,pre.op,pre.d);
            rep(i,0,3) {
                int nx=pre.x+dx[i],ny=pre.y+dy[i],nk=pre.k;
                if ((nx<0)||(nx>=n)||(ny<0)||(ny>=m)||(s[nx][ny]=='#')) continue;
                if (dis[nx][ny][nk][i]>pre.d+1) {
                    dis[nx][ny][nk][i]=pre.d+1;
                    q.push((hnode){nx,ny,nk,i,dis[nx][ny][nk][i]});
                }
                
            }
        }
        int ans=1e9;
        rep(i,0,k) rep(j,0,4) ans=min(ans,dis[ex][ey][i][j]);
        cout<<"Case #"<<cas<<": ";
        if (ans<1e9) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}