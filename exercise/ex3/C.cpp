//この渇き、奪ってくれるか
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 2000 + 100;
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

int n,d,a[N][N],s[N][N];

int query(int x1,int x2,int y1,int y2) {
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>d>>n;
    rep(i,1,n) {
        int x,y,w;
        cin>>x>>y>>w;
        a[x+1][y+1]=w;
    }
    rep(i,1,1025) rep(j,0,1025) 
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    int ans=0,cnt=0;
    rep(i,1,1025) rep(j,1,1025) {
        int tmp=query(max(1,i-d),min(i+d,1025),max(1,j-d),min(j+d,1025));
        if (tmp>ans) {ans=tmp;cnt=1;}
        else if (tmp==ans) cnt++;
    }
    cout<<cnt<<" "<<ans<<endl;

    return 0;
}