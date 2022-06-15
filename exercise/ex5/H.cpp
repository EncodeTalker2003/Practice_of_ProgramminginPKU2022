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

int sq[70][70],n,s,cnt[30],ans;

bool chk(int x,int y,int d) {
    if ((x+d-1>s)||(y+d-1>s)) return 0;
    rep(i,1,d) rep(j,1,d) 
        if (sq[x+i-1][y+j-1]) return 0;
    return 1;
}

void put(int x,int y,int d,int op) {
    rep(i,1,d) rep(j,1,d) sq[x+i-1][y+j-1]=op;
}

void dfs(int x,int y) {
    if (ans) return;
    if (y>s) {
        y=1;x++;
    }
    if (x>s) {
        ans=1;
        return;
    }
    //cout<<x<<" "<<y<<endl;
    if (sq[x][y]) {
        dfs(x,y+1);
        return;
    }
    rep(i,1,10) {
        if ((cnt[i])&&(chk(x,y,i))) {
            put(x,y,i,1);
            cnt[i]--;
            dfs(x,y+1);
            put(x,y,i,0);
            cnt[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        cin>>s>>n;
        rep(i,1,10) cnt[i]=0;
        rep(i,1,n) {
            int x;cin>>x;
            cnt[x]++;
        }
        int tmp=s*s;
        rep(i,1,10) rep(j,1,cnt[i]) tmp-=i*i;
        if (tmp!=0) {
            cout<<"NO"<<endl;
            continue;
        }
        ans=0;
        dfs(1,1);
        if (ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}