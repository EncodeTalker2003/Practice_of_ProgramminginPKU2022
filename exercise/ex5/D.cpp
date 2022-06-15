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

int n,m,bee[N],cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin>>m) {
        if (m==-1) break;
        n=0;
        while (1) {
            int x,y;
            cin>>x>>y;
            if (x==-1) break;
            n++;
            cnt[n]=x;bee[n]=y;
        }
        int ans=0;
        rep(i,1,n) {
            int sb=0,sc=0;
            rep(j,i,n) {
                sb+=bee[j];sc+=cnt[j];
                if (sb>m) break;
                //cout<<i<<" "<<j<<endl;
                ans=max(ans,sc);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}