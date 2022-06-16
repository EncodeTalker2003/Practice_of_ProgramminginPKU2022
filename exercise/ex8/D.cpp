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

int m,w[20],s[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>m;
    rep(i,0,14) cin>>w[i]>>s[i];
    int ans=0;
    rep(sta,0,(1<<15)-1) {
        int nows=m,ok=1,sumw=0;
        rep(i,0,14) {
            if ((sta>>i)&1) {
                if (nows<s[i]) {ok=0;break;}
                nows-=s[i];sumw+=w[i];
            }
        }
        if (!ok) continue;
        int c1=0,c2=0;
        rep(i,0,9) c1+=((sta>>i)&1);
        rep(i,10,14) c2+=((sta>>i)&1);
        if (c1>c2) continue;
        ans=max(ans,sumw);
    }
    cout<<ans<<endl;
    return 0;
}