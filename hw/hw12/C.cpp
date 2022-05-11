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

int n,m;
double v[N];

bool chk(double mid) {
    int cnt=0;
    rep(i,1,n) cnt+=v[i]/mid;
    return cnt>=m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;m++;
    rep(i,1,n) {
        int x;
        cin>>x;
        v[i]=pi*x*x;
    }
    //rep(i,1,n) cout<<v[i]<<" ";cout<<endl;
    double l=0,r=5e9,ans=0;
    while (r-l>1e-4) {
        double mid=(l+r)/2;
        if (chk(mid)) {ans=mid;l=mid;}
        else r=mid;
    }
    cout<<fixed<<setprecision(3)<<ans<<endl;
    return 0;
}