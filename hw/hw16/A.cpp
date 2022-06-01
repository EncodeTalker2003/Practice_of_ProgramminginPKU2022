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

int a[5][5],vis[5][5];
pii pre[5][5];
queue<pii> q;
vector<pii> ans;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    rep(i,0,4) rep(j,0,4) cin>>a[i][j];
    q.push(mkp(0,0));vis[0][0]=1;
    while (!q.empty()) {
        int x=q.front().fir,y=q.front().sec;q.pop();
        if ((x==4)&&(y==4)) {
            break;
        }
        rep(i,0,3) {
            int nx=x+dx[i],ny=y+dy[i];
            if ((nx<0)||(nx>4)||(ny<0)||(ny>4)||(a[nx][ny])||(vis[nx][ny])) continue;
            q.push(mkp(nx,ny));
            vis[nx][ny]=1;
            pre[nx][ny]=mkp(x,y);
        }
    }
    
    int nx=4,ny=4;
    while ((nx)||(ny)) {
        ans.pb(mkp(nx,ny));
        pii tmp=pre[nx][ny];
        nx=tmp.fir;ny=tmp.sec;
    }
    ans.pb(mkp(0,0));
    reverse(ans.begin(),ans.end());
    for (auto &x:ans) {
        cout<<"("<<x.fir<<", "<<x.sec<<")"<<endl;
    }
    return 0;
}