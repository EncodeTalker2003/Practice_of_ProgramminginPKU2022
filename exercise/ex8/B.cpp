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

bool chk(string s) {
    int n=s.size();
    rep(i,0,n-1) 
        if (s[i]!=s[n-i-1]) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        string s;
        cin>>s;
        int n=s.size(),ok=0;
        per(len,n,1) {
            rep(i,0,n-len) {
                string t=s.substr(i,len);
                if (chk(t)) {
                    cout<<t<<endl;
                    ok=1;break;
                }
            }
            if (ok) break;
        }
    }
    return 0;
}