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

int a[10][10],x[110],y[110],n,n1,n2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    a[0][2]=a[2][5]=a[5][0]=1;
    cin>>n>>n1>>n2;
    rep(i,0,n1-1) cin>>x[i];
    rep(i,0,n2-1) cin>>y[i];
    int cx=0,cy=0;
    int p=0,q=0;
    rep(i,0,n-1) {
        if (a[x[p]][y[q]]) cx++;
        if (a[y[q]][x[p]]) cy++;
        p=(p+1)%n1;q=(q+1)%n2;
    }
    if (cx>cy) cout<<"A";
    else if (cy>cx) cout<<"B";
    else cout<<"draw";
    return 0;
}