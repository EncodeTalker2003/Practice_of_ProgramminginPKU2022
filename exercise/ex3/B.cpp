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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;cin>>n;
    int ans=1e9;
    rep(i,1,n) rep(j,1,n/i) {
        if (n%(i*j)) continue;
        int k=n/(i*j);
        int now=i*j+i*k+j*k;
        ans=min(ans,now*2);
    }
    cout<<ans<<endl;
    return 0;
}