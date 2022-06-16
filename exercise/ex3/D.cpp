//この渇き、奪ってくれるか
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 65536 + 100;
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

unordered_map<int,int> f[N];

int dfs(int rst,int d) {
    //cout<<"solve "<<rst<<" "<<d<<endl;
    if (rst==d) return 1;
    if (rst<d) return 0;
    if (f[rst].count(d)) return f[rst][d];
    int tmp=dfs(rst,d+1);
    if (rst%d==0) tmp+=dfs(rst/d,d);
    f[rst][d]=tmp;
    return tmp;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while (T--) {
        int n;cin>>n;
        cout<<dfs(n,2)<<endl;
    }
    return 0;
}