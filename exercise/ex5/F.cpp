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

int a[10],n,ans;

void dfs(int d) {
    if (d==1) {
        rep(i,1,n) {
            if (a[i]==42) ans=1;
        }
        return;
    }
    rep(i,1,n) rep(j,i+1,n) {
        if ((a[i]==-1) || (a[j]==-1)) continue;
        int x=a[i],y=a[j];
        a[i]=x+y;a[j]=-1;
        dfs(d-1);
        a[i]=x-y;a[j]=-1;
        dfs(d-1);
        a[i]=x*y;a[j]=-1;
        dfs(d-1);
        a[i]=y-x;a[j]=-1;
        dfs(d-1);
        if ((y) && (x%y==0)) {
            a[i]=x/y;a[j]=-1;
            dfs(d-1);
        }
        if ((x)&&(y%x==0)) {
            a[i]=y/x;a[j]=-1;
            dfs(d-1);
        }
        a[i]=x;a[j]=y;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    dfs(n);
    if (ans) cout<<"YES";else cout<<"NO";
    return 0;
}