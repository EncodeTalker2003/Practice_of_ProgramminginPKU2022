//この渇き、奪ってくれるか
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

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

int n,a[20],b[20][20],goal[20],mp[20][20];

int calc() {
    int cnt=0;
    rep(i,1,n-1) mp[goal[i-1]][goal[i]]++;
    rep(i,1,n-1) {
        if (mp[a[i-1]][a[i]]) mp[a[i-1]][a[i]]--;
        else cnt++;
    }
    rep(i,1,n-1) mp[goal[i-1]][goal[i]]=0;
    return (cnt+2)/3;
}

bool dfs(int d,int mxd) {
    //cout<<"now ";
    //rep(i,0,n-1) cout<<a[i]<<" ";cout<<endl;
    int tmp=calc();
    if (!tmp) return 1;
    if (d+tmp>mxd) return 0;
    rep(l,1,n) rep(r,l,n) rep(k,r+1,n) {
        rep(i,1,n) b[d][i]=a[i];
        int p=l;
        rep(i,r+1,k) a[p++]=b[d][i];
        rep(i,l,r) a[p++]=b[d][i];
        if (dfs(d+1,mxd)) return 1;
        rep(i,1,n) a[i]=b[d][i];
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    rep(cas,1,T) {
        cin>>n;rep(i,1,n) cin>>a[i];
        rep(i,1,n) goal[i]=a[i];
        sort(goal+1,goal+1+n);
        //rep(i,1,n) assert(goal[i]>=0);
        int ans=-1;
        rep(i,0,5) {
            if (dfs(0,i)) {ans=i;break;}
        }
        cout<<"Case #"<<cas<<": ";
        if (ans>=0) cout<<ans<<endl;
        else cout<<"Can not finish in 5 steps"<<endl;
    }
    return 0;
}