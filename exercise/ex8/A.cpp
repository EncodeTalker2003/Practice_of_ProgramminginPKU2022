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

int a[10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    rep(i,1,5) rep(j,1,5) cin>>a[i][j];
    int ans=0;
    rep(i,1,5) rep(j,1,5) {
        int ok=1;
        rep(k,1,5) if (a[i][j]<a[i][k]) ok=0;
        rep(k,1,5) if (a[i][j]>a[k][j]) ok=0;
        if (ok) {
            ans=1;
            cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
            break;
        }
    }
    if (!ans) cout<<"not found"<<endl;
    return 0;
}