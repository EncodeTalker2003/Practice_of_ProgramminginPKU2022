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

int n,a[N],b[N];
string s,t;

int chk(){
    int cnt=0;
    rep(i,0,n-2) {
        if (a[i]!=b[i]) {
            rep(j,0,2) a[i+j]^=1;
            cnt++;
        }
        //rep(j,0,n-1) cout<<a[j];cout<<endl;
    }
    if (a[n-1]!=b[n-1]) return n+1;
    else return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>s>>t;
    n=s.size();
    rep(i,0,n-1) {
        a[i]=s[i]-'0';
        b[i]=t[i]-'0';
    }
    int ans=n+1;
    ans=min(ans,chk());
    rep(i,0,n-1) a[i]=s[i]-'0';
    a[0]^=1;a[1]^=1;
    ans=min(ans,chk()+1);
    if(ans>n)cout<<"impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}