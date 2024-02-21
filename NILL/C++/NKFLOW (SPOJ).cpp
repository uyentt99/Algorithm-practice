#include <bits/stdc++.h>

#define fu(i,a,b) for(int i=a; i<=b; i++)
#define N 1005

using namespace std;

int c[N][N], f[N][N], trc[N], n, m, s, t;

bool findway()
{
    fu(i,1,n) trc[i]=0;
    queue<int> qq;
    qq.push(s); trc[s]=-1;
    while ( !qq.empty() && trc[t]==0 )
    {
        int u;
        u=qq.front(); qq.pop();
        fu(v,1,n)
            if ( u == v ) continue;
            else if ( trc[v]==0 && f[u][v] < c[u][v] )
                    {
                        trc[v]=u; qq.push(v);
                    }
    }
    if ( trc[t] > 0 ) return true; else return false;
}

void FordFulkerson()
{
    while ( findway() )
    {
        int delta=1000005;
        for(int u=t; trc[u]>0; u=trc[u]) delta=min(delta,c[trc[u]][u]-f[trc[u]][u]);
        for(int u=t; trc[u]>0; u=trc[u])
        {
            f[trc[u]][u]+=delta;
            f[u][trc[u]]-=delta;
        }
    }
}

int main()
{
    cin>>n>>m>>s>>t;
    fu(i,1,m)
    {
        int u, v, c1;;
        cin>>u>>v>>c1; c[u][v]=c1;
    }
    FordFulkerson();
    int ans=0;
    fu(v,1,n)
        if ( c[s][v] > 0 ) ans+=f[s][v];
    cout<<ans<<'\n';
    return 0;
}
