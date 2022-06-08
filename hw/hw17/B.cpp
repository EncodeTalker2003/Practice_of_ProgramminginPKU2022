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

int dis[310][310];
pii from[310][310],op[310][310];
queue<pii> q;
vector<pii> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    rep(i,0,a) rep(j,0,b) dis[i][j]=maxd;
    dis[0][0]=0;
    q.push(mkp(0,0));
    pii fin=mkp(-1,-1);
    while (!q.empty()) {
        pii pre=q.front();q.pop();
        //cout<<pre.fir<<" "<<pre.sec<<endl;
        if ((pre.fir==c)||(pre.sec==c)) {
            fin=pre;
            break;
        }
        if ((pre.fir!=a) && (dis[a][pre.sec]==maxd)) {
            dis[a][pre.sec]=dis[pre.fir][pre.sec]+1;
            from[a][pre.sec]=pre;
            op[a][pre.sec]=mkp(1,1);
            q.push(mkp(a,pre.sec));
        } 
        if ((pre.sec!=b)&&(dis[pre.fir][b]==maxd)) {
            dis[pre.fir][b]=dis[pre.fir][pre.sec]+1;
            from[pre.fir][b]=pre;
            op[pre.fir][b]=mkp(1,2);
            q.push(mkp(pre.fir,b));
        }
        if ((pre.fir)&&(dis[0][pre.sec]==maxd)) {
            dis[0][pre.sec]=dis[pre.fir][pre.sec]+1;
            from[0][pre.sec]=pre;
            op[0][pre.sec]=mkp(2,1);
            q.push(mkp(0,pre.sec));
        }
        if ((pre.sec)&&(dis[pre.fir][0]==maxd)) {
            dis[pre.fir][0]=dis[pre.fir][pre.sec]+1;
            from[pre.fir][0]=pre;
            op[pre.fir][0]=mkp(2,2);
            q.push(mkp(pre.fir,0));
        }
        //cout<<"pre "<<pre.fir<<" "<<pre.sec<<endl;
        int tmp=min(a-pre.fir,pre.sec);
        pii now=mkp(pre.fir+tmp,pre.sec-tmp);
        //cout<<"now "<<now.fir<<" "<<now.sec<<endl;
        if (dis[now.fir][now.sec]==maxd) {
            dis[now.fir][now.sec]=dis[pre.fir][pre.sec]+1;
            from[now.fir][now.sec]=pre;
            op[now.fir][now.sec]=mkp(3,1);
            q.push(now);
        }
        tmp=min(b-pre.sec,pre.fir);
        now=mkp(pre.fir-tmp,pre.sec+tmp);
        //cout<<"now "<<now.fir<<" "<<now.sec<<endl;
        if (dis[now.fir][now.sec]==maxd) {
            dis[now.fir][now.sec]=dis[pre.fir][pre.sec]+1;
            from[now.fir][now.sec]=pre;
            op[now.fir][now.sec]=mkp(3,2);
            q.push(now);
        }
    }
    if (fin.fir==-1) {
        cout<<"impossible"<<endl;
        return 0;
    }
    cout<<dis[fin.fir][fin.sec]<<endl;
    int now=dis[fin.fir][fin.sec];
    rep(i,1,now) {
        ans.pb(op[fin.fir][fin.sec]);
        fin=from[fin.fir][fin.sec];
        //cout<<fin.fir<<" "<<fin.sec<<endl;
    }
    reverse(ans.begin(),ans.end());
    for (auto &x:ans) {
        if (x.fir==1) {
            cout<<"FILL("<<x.sec<<")"<<endl;
        } else if (x.fir==2) {
            cout<<"DROP("<<x.sec<<")"<<endl;
        } else if (x.fir==3) {
            cout<<"POUR("<<3-x.sec<<","<<x.sec<<")"<<endl;
        }
    }
    return 0;
}