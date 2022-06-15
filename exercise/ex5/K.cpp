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
#define eps 1e-6

vi now,ans;
int ok;

int cmp(double x,double y) {
    if (x-y>eps) return 1;
    else if (x-y<-eps) return -1;
    else return 0;
}

void dfs(int d,int rst,double s) {
    if ((ok) || (cmp(s,1)==1)) return;
    if (!rst) {
        if (cmp(s,1)==0) {
            for(auto x:now) ans.pb(x);
            ok=1;
        }
        return;
    }
    if (cmp(1.0/d*((rst-1)/d+1),1.0-s)==-1) return;
    int p=0;
    rep(i,d,rst) {
        now.pb(i);
        dfs(i,rst-i,s+1.0/i);
        now.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        int n;cin>>n;
        ans.clear();now.clear();ok=0;
        dfs(1,n,0);
        if (ok) {
            cout<<ans.size()<<" ";
            for (auto x:ans) cout<<x<<" ";
            cout<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
    return 0;
}