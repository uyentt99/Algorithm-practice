#include <bits/stdc++.h>
#define task "PBCGANGS"
using namespace std;
typedef long long LL;
void pre(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
//
const int N=1e5+5;
int p[N], thu[N];
//tim tap hop ma nut i thuoc
int findSet(int u){
    if (p[u]<0) return u;
    p[u] = findSet(p[u]);
    return p[u];
}
//Ghep hai tap hop chua u, v
void unionSet(int u, int v){
    int r = findSet(u);
    int s = findSet(v);
    //u va v da co chung cha nen khong can ghep nua
    if (r==s) return;
    //ghep 2 tap hop co goc la r va s
    int x = p[r] + p[s];
    if (p[r]>p[s]) {
        //cay goc s chua nhieu phan tu hon cay goc r
        p[r]=s;
        p[s]=x;
    }else {
        //cay goc r chua nhieu phan tu hon cay goc s
        p[s]=r;
        p[r]=x;
    }
}
main(){
    pre();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    //Khoi tao
    for(int i=1; i<=n; i++) p[i]=-1;

    for(int i=1; i<=m; ++i){
        char ch;
        int u,v;
        cin>>ch>>u>>v;
        if (ch=='F')
            //u va v la ban, ghep hai tap chua u, v
            unionSet(u,v);
        else{
            if (thu[u]==0)
                thu[u]=v;
            else
                //ke thu cua u va v ghep voi nhau
                unionSet(thu[u],v);

            if (thu[v]==0)
                thu[v]=u;
            else
                //u va ke thu cua v ghep voi nhau
                unionSet(u,thu[v]);
        }
    }

    int d=0;
    for(int i=1; i<=n; ++i) if (p[i]<0) d++;
    cout<<d;
}
