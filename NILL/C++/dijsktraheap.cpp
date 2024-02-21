#include <bits/stdc++.h>
#define Fu( i, a, b) for( int i=a; i<=b; i++)
#define Fd( i, a, b) for( int i=a; i>=b; i--)
#define Ft( i, a, b) for( int i=a; i<b; i++)
#define pb push_back
using namespace std;
const int N = 505;
const int oo = 500 * 10000;
struct edge {int v, t, c;};
struct ele {
  int u, c;
  bool operator<(const ele& x) const {return c > x.c;}
};
int b[N], d[N], n, m;
vector<edge> g[N], ev[N];
//
void dijkstra(int s) {
    Fu( i, 1, n) d[i] = oo;
    d[s] = 0;
    priority_queue<ele> q;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().u;
        int c = q.top().c;
        q.pop();
        if (c != d[u]) continue;
        Ft( i, 0, g[u].size()){
            int v = g[u][i].v;
            int t = c + g[u][i].t;
            if (d[v] > t) d[v] = t, q.push({v, t});
        }
    }
}
//
struct cmp {
  bool operator()(const ele& x, const ele& y) const {
    return x.c < y.c;
  }
};
//
bool check(int val, int st, int en) {
    memset(d, -1, sizeof(d));
    d[st] = val;
    priority_queue<ele, std::vector<ele>, cmp> q;
    q.push({1, val});
    while (!q.empty()) {
        int u = q.top().u;
        int c = q.top().c;
        q.pop();
        if (c != d[u]) continue;
        if (b[u]) c = val;
        for (int i = 0; i < int(ev[u].size()); ++i) {
            int v = ev[u][i].v;
            int t = c - ev[u][i].c;
            if (t>= 0 && d[v] < t) d[v] = t, q.push({v, t});
        }
    }
    return d[en] != -1;
}
//............................
main() {
   // freopen( "a.inp", "r", stdin);
   // freopen( "a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Fu( i, 1, n) cin >>b[i];
    cin >> m;
    Fu( i, 1, m){
        int u, v, t, c; cin >>u >>v >>t >>c;
        g[u].pb({v, t, c});
        g[v].pb({u, t, c});
    }
    dijkstra(1);
    Fu( i, 1, n) Ft( j, 0, g[i].size())
        if (d[i] + g[i][j].t == d[g[i][j].v])
            ev[i].pb(g[i][j]);

    int dau=1, cuoi=oo;
    while (dau<cuoi){
        int mid = (dau + cuoi) >> 1;
        if (check(mid, 1, n)) cuoi = mid;
        else dau = mid + 1;
    }
    cout <<dau;
}
