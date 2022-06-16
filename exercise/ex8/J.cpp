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

struct node{int n,s,cnt;};
queue<node> q;
int n,m;
unordered_map<int,int> mp;

void out(node p) {
    cout<<p.cnt<<endl;
    per(i,p.cnt-1,0) {
        if ((p.s>>i)&1) cout<<"O";
        else cout<<"H";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin>>n>>m) {
        if ((n==0)&&(m==0)) break;
        if (n==m) {
            cout<<0<<endl<<endl;
            continue;
        }
        while (!q.empty()) q.pop();
        q.push((node){n,0,0});
        mp.clear();
        while (!q.empty()) {
            node pre=q.front();q.pop();
            //if (pre.cnt>5) break;
            //cout<<pre.n<<endl;
            node now=pre;
            now.n*=3;now.s<<=1;now.cnt++;
            if (now.n==m) {
                out(now);
                break;
            }
            if (!mp[now.n]) {
                mp[now.n]=1;
                q.push(now);
            }
            now=pre;
            now.n/=2;now.s<<=1;now.s|=1;now.cnt++;
            if (now.n==m) {
                out(now);
                break;
            }
            if (!mp[now.n]) {
                mp[now.n]=1;
                q.push(now);
            }
        }
    }
    return 0;
}