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

int ans,vis[10],n,m;
string s[10];

void dfs(int row, int lft) {
    if (row==n) {
        ans+=(lft==0);
        return;
    }
    if (n-row<lft) return;
    dfs(row+1,lft);
    if (lft==0) return;
    rep(i,0,n-1) {
        if ((s[row][i]=='.')||(vis[i])) continue;
        vis[i]=1;
        dfs(row+1,lft-1);
        vis[i]=0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin>>n>>m) {
        if ((n==-1)&&(m==-1)) break;
        rep(i,0,n-1) cin>>s[i];
        ans=0;
        dfs(0,m);
        cout<<ans<<endl;
    }
    return 0;
}