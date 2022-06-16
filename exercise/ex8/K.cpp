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

int n,m,K,h,f[1010][1010][11],a[1010],b[1010],c[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>K>>m>>h;
    rep(i,1,n) cin>>a[i]>>b[i]>>c[i];
    memset(f,-0x3f,sizeof(f));
    f[0][m][K]=0;
    int ans=0;
    rep(i,0,n-1) {
        rep(j,1,m) {
            rep(k,0,K) {
                if (f[i][j][k]<0) continue;
                //cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
                if (f[i][j][k]+b[i+1]>=h) {
                        ans=i+1;
                        break;
                    }
                if (j>a[i+1]) {
                    f[i+1][j-a[i+1]][k]=max(f[i+1][j-a[i+1]][k],f[i][j][k]+b[i+1]);
                }
                if (min(m,j+c[i+1])>a[i+1]) {
                    int jj=min(m,j+c[i+1])-a[i+1];
                    f[i+1][jj][k]=max(f[i+1][jj][k],f[i][j][k]);
                }
                if (k) {
                    f[i+1][j][k-1]=max(f[i+1][j][k-1],f[i][j][k]);
                }
            }
            if (ans) break;
        }
        if (ans) break;
    }
    if (ans) cout<<ans<<endl;
    else cout<<"Fail"<<endl;
    return 0;
}