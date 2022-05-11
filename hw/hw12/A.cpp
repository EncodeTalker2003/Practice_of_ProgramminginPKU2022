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

int n,mv[10],ans[10],a[10],b[10],vis[10][10];

void chk() {
    rep(i,1,9) b[i]=a[i];
    rep(i,1,9) rep(j,1,9)
        if (vis[i][j]) b[j]=(b[j]+mv[i])%4;
    rep(i,1,9) 
        if (b[i]) return;
    if (ans[0]>mv[0]) {
        rep(i,0,9) ans[i]=mv[i];
    }
}


void dfs(int d) {
    if (d>9) {
        chk();
        return;
    }
    rep(i,0,3) {
        mv[0]+=i;mv[d]=i;
        dfs(d+1);
        mv[0]-=i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vis[1][1]=vis[1][2]=vis[1][4]=vis[1][5]=1;
    vis[2][1]=vis[2][2]=vis[2][3]=1;
    vis[3][2]=vis[3][3]=vis[3][5]=vis[3][6]=1;
    vis[4][1]=vis[4][4]=vis[4][7]=1;
    vis[5][2]=vis[5][4]=vis[5][5]=vis[5][6]=vis[5][8]=1;
    vis[6][3]=vis[6][6]=vis[6][9]=1;
    vis[7][4]=vis[7][5]=vis[7][7]=vis[7][8]=1;
    vis[8][7]=vis[8][8]=vis[8][9]=1;
    vis[9][5]=vis[9][6]=vis[9][8]=vis[9][9]=1;
    rep(i,1,9) cin>>a[i];
    ans[0]=1e9;
    dfs(1);
    rep(i,1,9) rep(j,1,ans[i])
        cout<<i<<" ";
    return 0;
}