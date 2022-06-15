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

int n,a[N],b[N],c[N],f[N][6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) cin>>b[i];
    rep(i,1,n) cin>>c[i];
    if (n==1) {
        cout<<a[1]<<endl;
        return 0;
    }
    f[1][0]=f[1][2]=f[1][4]=a[1];
    f[1][1]=f[1][3]=f[1][5]=b[1];
    rep(i,2,n-1) {
        f[i][0]=max(f[i-1][0],max(f[i-1][2],f[i-1][4]))+b[i];
        f[i][1]=max(f[i-1][0],max(f[i-1][2],f[i-1][4]))+c[i];
        f[i][2]=max(f[i-1][1],max(f[i-1][3],f[i-1][5]))+a[i];
        f[i][3]=max(f[i-1][0],max(f[i-1][2],f[i-1][4]))+c[i];
        f[i][4]=max(f[i-1][1],max(f[i-1][3],f[i-1][5]))+a[i];
        f[i][5]=max(f[i-1][1],max(f[i-1][3],f[i-1][5]))+b[i];
    }
    int tmp1=max(f[n-1][0],max(f[n-1][2],f[n-1][4]))+b[n];
    int tmp2=max(f[n-1][1],max(f[n-1][3],f[n-1][5]))+a[n];
    int ans=max(tmp1,tmp2);
    cout<<ans<<endl;
    return 0;
}