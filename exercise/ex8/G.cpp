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

int n,f[210][210],a[210];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    rep(cas,1,T) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) rep(j,i,n) f[i][j]=maxd;
        rep(i,1,n) f[i][i]=1;
        rep(i,1,n-1) f[i][i+1]=1+(a[i]!=a[i+1]);
        rep(len,3,n) {
            rep(i,1,n-len+1) {
                int j=i+len-1;
                rep(k,i,j-1) {
                    if (a[k]==a[j]) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j-1]);
                    else f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
                }
            }
        }
        cout<<"Case "<<cas<<": "<<f[1][n]<<endl;
    }
    return 0;
}