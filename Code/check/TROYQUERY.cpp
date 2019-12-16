#include <bits/stdc++.h>
#define task "TROYQuery"
using namespace std;
typedef long long LL;
void pre(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
//
const int maxXY = 1e5;
const int N = 4e5 + 4;
vector <int> comp[N+1];
int par[N+1], i, n;
LL x[N], y[N];
bool need[N];
bool check;

inline int le(int k) { return N - k; }

void unionSet(int u, int v){
	u = par[u];
	v = par[v];
	if(u == v)
		return;
	if(comp[u].size() > comp[v].size())
		swap(u, v);

	for(int i=0; i < comp[u].size(); ++i){
        int x = comp[u][i];
		if(par[le(x)] == v){
            check = true;
            return;
        }
		comp[v].push_back(x);
		par[x] = v;
	}
}

int main(){
    pre();
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> x[i] >> y[i] >> a >> b;
		need[i] = (a != b);
	}
    //makeSet
	for(int i = 0; i <4*maxXY; ++i){
		comp[i].push_back(i);
		par[i] = i;
		comp[le(i)].push_back(le(i));
		par[le(i)] = le(i);
	}

    //union
	check = false;
	for(int i = 0; i < n; ++i){
		int r = x[i];
		int c = maxXY + y[i];
		if(need[i]){
			unionSet(r, le(c));
			unionSet(le(r), c);
		}else{
			unionSet(r, c);
			unionSet(le(r), le(c));
		}
		if (check){
            for (int j=i; j<n; ++j) cout<<"No\n";
            exit(0);
		}
		cout << "Yes\n";
	}
}
