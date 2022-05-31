//この渇き、奪ってくれるか
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 2000000 + 100;
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

int n,c[21],d[21],f[N],s[N];
ll ord[N];
string name[21];
vi ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        cin>>n;
        rep(i,0,n-1) cin>>name[i]>>d[i]>>c[i];
        rep(i,1,(1<<n)-1) f[i]=maxd;
        rep(sta,1,(1<<n)-1) {
            s[sta]=0;
            rep(i,0,n-1) 
                if ((sta>>i)&1) s[sta]+=c[i];
        }
        //rep(i,0,(1<<n)-1) cout<<s[i]<<" ";cout<<endl;
        rep(sta,1,(1<<n)-1) {
            rep(i,0,n-1) {
                if ((sta>>i)&1) {
                    int pre=sta^(1<<i);
                    int tmp=f[pre]+max(0,s[sta]-d[i]);
                    ll nord=(ord[pre]<<4)+i;
                    //cout<<sta<<" "<<i<<" "<<tmp<<endl;
                    if ((tmp<f[sta])||((tmp==f[sta])&&(nord<ord[sta]))) {
                        f[sta]=tmp;
                        ord[sta]=nord;
                    }
                }
            }
        }
        //rep(i,0,(1<<n)-1) cout<<f[i]<<" ";cout<<endl;
        cout<<f[(1<<n)-1]<<endl;
        ll tmp=ord[(1<<n)-1];
        ans.clear();
        rep(i,0,n-1) {
            int x=tmp&15;
            ans.pb(x);
            tmp>>=4;
        }
        per(i,n-1,0) cout<<name[ans[i]]<<endl;
    }
    return 0;
}