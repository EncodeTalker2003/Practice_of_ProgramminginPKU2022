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

int n,a[510][510],f[510][510][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n) {
        string s;
        cin>>s;
        rep(j,1,n) {
            if (i==j) continue;
            if (s[j-1]=='W') a[i][j]=1;
        }
    }
    rep(i,1,n) f[i][i][0]=f[i][i][1]=1;
    rep(len,2,n) rep(i,1,n-len+1) {
        int j=i+len-1;
        rep(k,i+1,j) {
            if ((a[i][k])&&(f[i+1][k][1])&&(f[k][j][0])) f[i][j][0]=1;
        }
        rep(k,i,j-1) {
            if ((a[j][k])&&(f[i][k][1])&&(f[k][j-1][0])) f[i][j][1]=1;
        }
    }
    rep(i,1,n) {
        if ((f[1][i][1])&&(f[i][n][0])) cout<<i<<" ";
    }
    return 0;
}