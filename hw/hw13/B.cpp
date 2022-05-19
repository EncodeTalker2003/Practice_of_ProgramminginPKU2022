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
#define blank "|     "

bool fin;

void outb(int n) {
	rep(i,1,n) cout<<blank;
}

void solve(int d) {
	string f[40],s;
	int n=0;
	while (cin>>s) {
		if (s[0]=='d') {
			outb(d);
			cout<<s<<endl;
			solve(d+1);
		} else if (s[0]=='f') {
			f[++n]=s;
		} else if ((s[0]=='*')||(s[0]==']')) {
			sort(f+1,f+1+n);
			rep(i,1,n) {
				outb(d-1);
				cout<<f[i]<<endl;
			}
			if (s[0]=='*') {
				fin=1;
				cin.get();
			}
			break;
		} else assert(0);
		if (fin) break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("a.out","w",stdout);
	int cas=0;
	while (cin.peek()!='#') {
		cas++;fin=0;
		//cout<<cin.peek()<<endl;
		cout<<"DATA SET "<<cas<<":"<<endl;
		cout<<"ROOT"<<endl;
		solve(1);
		cout<<endl;
	}
	return 0;

}