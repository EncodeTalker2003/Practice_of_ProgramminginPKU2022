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

char s[5020][5020];

void solve(int x,int y,int d) {
    if (d==0) return;
    if (d==1) {
        s[x][y]='/';
        s[x][y+1]='\\';
        s[x+1][y-1]='/';
        s[x+1][y+2]='\\';
        s[x+1][y]=s[x+1][y+1]='_';
        return;
    }
    solve(x,y,d-1);
    solve(x+(1<<(d-1)),y-(1<<(d-1)),d-1);
    solve(x+(1<<(d-1)),y+(1<<(d-1)),d-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    //freopen("a.out","w",stdout);
    while (cin>>n) {
        if (!n) break;
        int h=(1<<n),w=(1<<(n+1));
        rep(i,0,h-1) rep(j,0,w-1) s[i][j]=' ';
        solve(0,(w>>1)-1,n);
        int now=(1<<n)+1;
        rep(i,0,h-1) {
            rep(j,0,now-1) cout<<s[i][j];
            cout<<endl;
            now++;
        }
        cout<<endl;
    }
}