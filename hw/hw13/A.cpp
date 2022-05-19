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

int num[N],op[N],tp1,tp2;
string s;

void calc() {
    assert(tp2);
    if (op[tp2]==1) {
        int x=num[tp1--],y=num[tp1--];
        num[++tp1]=(x|y);
    } else if (op[tp2]==2) {
        int x=num[tp1--],y=num[tp1--];
        num[++tp1]=(x&y);
    } else if (op[tp2]==3) {
        int x=num[tp1--];
        num[++tp1]=(x^1);
    }
    tp2--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cas=0;
    while (getline(cin,s)) {
        int n=s.size();cas++;
        tp1=tp2=0;
        rep(i,0,n-1) {
            if (s[i]==' ') {
                continue;
            } else if (s[i]=='V') {
                num[++tp1]=1;
            } else if (s[i]=='F') {
                num[++tp1]=0;
            } else if (s[i]=='(') {
                op[++tp2]=0;
            } else if (s[i]=='|') {
                while ((tp2)&&(op[tp2]>1)) calc();
                op[++tp2]=1;
            } else if (s[i]=='&') {
                while ((tp2)&&(op[tp2]>2)) calc();
                op[++tp2]=2;
            } else if (s[i]=='!') {
                op[++tp2]=3;
            } else if (s[i]==')') {
                while ((tp2)&&(op[tp2]>0)) calc();
                assert(tp2>0);
                tp2--;
            }
            /*cout<<"now "<<i<<endl;
            rep(j,1,tp1) cout<<num[j]<<" ";cout<<endl;
            rep(j,1,tp2) cout<<op[j]<<" ";cout<<endl<<endl;*/
        }
        while (tp2) calc();
        char ans;
        if (num[tp1]) ans='V';else ans='F';
        cout<<"Expression "<<cas<<": "<<ans<<endl;
    }
    return 0;
}
