#include <bits/stdc++.h>
#define Fu(i,a,b) for( int i=(a); i<=(b); i++)
#define Fd(i,a,b) for( int i=(a); i>=(b); i--)
#define pb push_back
using namespace std;
const int N=1e5+10;
struct edg{int u,v,w;} c[N];
struct onetask{
    int a,b,c,id;
    bool operator < (const onetask tk) const { return c<tk.c;}
} task[N];
struct gtw{
    int w, id;
    bool operator < (const gtw gt) const { return w<gt.w;}
} canh[N];
vector<int> g[N];
int dp[N][50], h[N], maxlog, res[N];
int vt[N], sl[N], num ;
int f1[N], f2[N], n, m;
//
void pre(){
    #ifndef ONLINE_JUDGE
    freopen("network.inp","r",stdin);
    freopen("network.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
//
void dfs(int u, int p, int k) {
    vt[u]=++num;
    dp[u][0] = p;
    h[u]=k;
    sl[u] = 1;
    for( int i=0; i<g[u].size(); i++) {
        int j = g[u][i];
        int v = u^c[j].u^c[j].v;
        if (v != p) {
            dfs(v, u, k + 1);
            sl[u]+=sl[v];
        }
    }
}
//
int lca(int u, int v){
  if (h[u] < h[v]) swap(u, v);
  Fd(i,maxlog,0) if (h[u] - (1 << i) >= h[v])  u = dp[u][i];
  if (u == v) return u;
  Fd(i,maxlog,0) if (dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
    }
  return dp[u][0];
}
//
void update1(int i,int w){
    for(;i<=n; i+=i&(-i)) f1[i]+=w;
}
int get1(int i){
    int s=0;
    for(;i>0;i-=i&(-i)) s+=f1[i];
    return s;
}
void process1( onetask x){
    int u=lca(x.a,x.b);
    res[x.id] = get1(vt[x.a])+get1(vt[x.b])-2*get1(vt[u]);
}
//
void update2(int i){
    for(;i<=n; i+=i&(-i)) f2[i]++;
}
int get2(int i){
    int s=0;
    for(;i>0;i-=i&(-i)) s+=f2[i];
    return s;
}
void process2( onetask x){
    int u=c[x.b].u;
    int v=c[x.b].v;
    int s=get2(vt[v]+sl[v]-1)-get2(vt[v]);
    if (h[u]<h[v]) res[x.id] = s;
    else {
            res[x.id] = get2(1)-s;
            if (c[x.id].w<=x.c) res[x.id]--;
    }
}
//
void them(int id){
    int u=c[id].u, v=c[id].v;
    int x;
    if (h[u]<h[v]) x =v; else x=u;
    update1(vt[x],1);
    update1(vt[x]+sl[x],-1);
    update2(vt[x]);
}
//
void enter(){
    cin>>n>>m;
    Fu(i,1,n-1){
        cin>>c[i].u>>c[i].v>>c[i].w;
        g[c[i].u].pb(i);
        g[c[i].v].pb(i);
        canh[i]={c[i].w,i};
    }
    Fu(i,1,m){
        char pas; cin>>pas;
        if (pas=='P') {
             int a, b, c; cin>>a>>b>>c;
             task[i]={a,b,c,i};
        }else {
             int b, c; cin>>b>>c;
             task[i]={-1,b,c,i};
        }
    }
    sort(canh+1,canh+n);
    sort(task+1,task+1+m);
}
//
main(){
    pre();
    enter();
    num=0;
    dfs(1,0,1);
    for (int j = 1; 1 << j <= n; ++j){
        Fu(i,1,n) dp[i][j] = dp[dp[i][j - 1]][j - 1];
        maxlog=j;
    }
    int j=1;
    Fu(i,1,m) {
        while (j<n && canh[j].w <= task[i].c) them(canh[j].id), j++;
        if (task[i].a==-1) process2(task[i]);
            else process1(task[i]);
    }
    Fu(i,1,m) cout<<res[i]<<"\n";
}
