//この渇き、奪ってくれるか
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 50+10;
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

struct BigInt{
    int len,x[N];

    BigInt(string s="0") {
        memset(x,0,sizeof(x));
        len=s.size();
        rep(i,0,len-1) x[i]=s[len-i-1]-'0';
    }

    void setmax() {
        len=56;
        rep(i,0,55) x[i]=9;
    }

    bool operator <(const BigInt &a) const {
        if (len!=a.len) return len<a.len;
        per(i,len-1,0) {
            if (x[i]!=a.x[i]) return x[i]<a.x[i];
        }
        return 0;
    }

    void out() {
        per(i,len-1,0) cout<<x[i];
    }

    BigInt operator +(BigInt a) {
        BigInt c;
        c.len=max(a.len,len)+1;
        rep(i,0,c.len-1) {
            c.x[i]+=a.x[i]+x[i];
            if (c.x[i]>9) {
                c.x[i+1]+=c.x[i]/10;
                c.x[i]%=10;
            }
        }
        while ((c.len>1)&&(c.x[c.len-1]==0)) c.len--;
        return c;
    }

    
}f[N][N];
int n,m;
string s;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin>>m) {
        cin>>s;
        n=s.size();
        rep(i,0,n-1) rep(j,0,m) f[i][j].setmax();
        f[0][0]=BigInt(s.substr(0,1));
        rep(i,1,n-1) {
            f[i][0]=BigInt(s.substr(0,i+1));
            rep(j,1,m)  rep(k,0,i-1) {
                f[i][j]=min(f[i][j],f[k][j-1]+BigInt(s.substr(k+1,i-k)));
            }
        }
        /*rep(i,0,n-1) {
            rep(j,0,m) {if (f[i][j].len<50) f[i][j].out();cout<<' ';}
            cout<<endl;
        }*/
        f[n-1][m].out();
        cout<<endl;
    }
    return 0;
}