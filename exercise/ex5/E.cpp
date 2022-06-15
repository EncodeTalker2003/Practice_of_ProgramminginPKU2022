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

int pw[10];
char ch[5050][5050];

void solve(int lx,int rx,int ly,int ry,int n) {
    //cout<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<" "<<n<<endl;
    if (n==1) {
        ch[lx][ly]='X';
        return;
    }
    solve(lx,lx+pw[n-2]-1,ly,ly+pw[n-2]-1,n-1);
    solve(rx-pw[n-2]+1,rx,ly,ly+pw[n-2]-1,n-1);
    solve(lx,lx+pw[n-2]-1,ry-pw[n-2]+1,ry,n-1);
    solve(rx-pw[n-2]+1,rx,ry-pw[n-2]+1,ry,n-1);
    solve(lx+pw[n-2],rx-pw[n-2],ly+pw[n-2],ry-pw[n-2],n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pw[0]=1;
    rep(i,1,7) pw[i]=pw[i-1]*3;
    int n;
    while (cin>>n) {
        if (n==-1) break;
        rep(i,1,pw[n-1]) rep(j,1,pw[n-1]) ch[i][j]=' ';
        solve(1,pw[n-1],1,pw[n-1],n);
        rep(i,1,pw[n-1]) {
            rep(j,1,pw[n-1]) cout<<ch[i][j];
            cout<<endl;
        }
        cout<<'-'<<endl;
    }
    return 0;
}