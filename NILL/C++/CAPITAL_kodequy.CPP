#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define mp make_pair
#define ft first
#define sc second
const int maxn=3*1e5+5;
int n,m;
int s[maxn],cl[maxn],cur[maxn];
int p[maxn];
int num[maxn],low[maxn];
int x[maxn],sn,khop[maxn];
int id,tplt;
vector<int> a[maxn];
pair<int,int > e[maxn];

void nhap()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CAPITAL.INP","r",stdin);
    freopen("CAPITAL.OUT","w",stdout);
    cin>>n>>m;
    fore(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        e[i]=mp(u,v);
    }
    sort(e+1,e+m+1);
    m=unique(e+1,e+m+1)-e-1;
    fore(i,1,m)
    {
        int u=e[i].ft;
        int v=e[i].sc;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int xp)
{
    int sn=0;
    s[++sn]=xp;
    cl[xp]=1;
    p[xp]=0;
    num[xp]=low[xp]=++id;
    while(sn>0)
    {
        int u=s[sn];
        if(cur[u]<a[u].size())
        {
            int v=a[u][cur[u]++];
            if(v!=p[u])
            {
                if(cl[v]==0)
                {
                    s[++sn]=v;
                    cl[v]=1;
                    p[v]=u;
                    num[v]=low[v]=++id;
                }else low[u]=min(low[u],num[v]);
            }
        }
        else
        {
            int w=p[u];
            if(w)low[w]=min(low[w],low[u]);
            --sn;
        }
    }
}

void timkhop()
{
    fore(u,1,n)
    {
        khop[u]=0;
        if(p[u]==0)
        {
            for(int i=0;i<a[u].size();i++)
            {
                int v=a[u][i];
                if(p[v]==u)khop[u]++;
            }
            if(khop[u])--khop[u];
        }
        else
        {
            for(int i=0;i<a[u].size();i++)
            {
                int v=a[u][i];
                 if(p[v]==u && low[v]>=num[u])khop[u]++;
            }
        }
    }
    int io=0;
    int ans=-1;
    fore(i,1,n)
     if(khop[i]>ans)
     {
         ans=khop[i];
         io=i;
     }
    cout<<ans+tplt<<' '<<io<<endl;
}

void xuli()
{
    fore(i,1,n)cur[i]=cl[i]=0;
    fore(i,1,n)
        if(cl[i]==0)
        {
            tplt++;
            dfs(i);
        }
    timkhop();
}

int main()
{
    nhap();
    xuli();
}
