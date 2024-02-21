#include <bits/stdc++.h>
#define Fu(i,a,b) for(int i=(a); i<=(b); i++)
#define Fd(i,a,b) for(int i=(a); i>=(b); i--)
using namespace std;
const int N=2e5+100;
int n;
//_____________________BIT_________________
struct fenwick{
    int f[N];
    void reset() { Fu(i,1,n) f[i]=0; }
    void update(int i){
        for( ; i<=n; i+=i&(-i)) f[i]++;
    }
    int get(int i){
        int sum=i;
        for( ; i; i-=i&(-i)) sum-=f[i];
        return sum;
    }
};
fenwick a,b,c;
//_________________BIT2D______________________
const int M=1e4;
struct Fenwick2D {
    int T[M][M];
    int n, m;
    void clear(int n, int m) {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                T[i][j] = 0;

        this->n = n;
        this->m = m;
    }
    void adjust(int x, int y, int v) {
        for (int i=x; i <= n; i += (i&-i))
            for(int j=y; j <= m; j += (j&-j))
                T[i][j] += v;
    }
    int rsq(int x, int y) {
        int sum = 0;
        for(int i=x; i; i -= (i&-i))
            for(int j=y; j; j -= (j&-j))
                sum += T[i][j];
        return sum;
    }
    int rsq(int x1, int y1, int x2, int y2) {
        return rsq(x2, y2) - rsq(x2, y1-1) - rsq(x1-1, y2) + rsq(x1-1, y1-1);
    }
};
/*
void lazyup(int k, int l, int r)
{
    if (laz[k]==0)return;
    c[k]+=laz[k];
    laz[2*k]+=laz[k];
    laz[2*k+1]+=laz[k];
    laz[k]=0;
}
int pop(int k, int l, int r, int u, int v)
{
    lazyup(k, l, r);
    if (l>v || r<u) return(0);
    if (l>=u && r<=v) return(c[k]);
    int g=(l+r)/2;
    return max(pop(2*k, l, g, u, v), pop(2*k+1, g+1, r, u, v));
}
void upd(int k, int l, int r, int u, int v, int w)
{
    lazyup(k, l, r);
    if (l>v || r<u) return;
    if (l>=u && r<=v){
        laz[k]=w;
        lazyup(k, l, r);
        return;
    }
    int g=(l+r)/2;
    upd(2*k, l, g, u, v, w);
    upd(2*k+1, g+1, r, u, v, w);
    c[k]=max(c[2*k+1], c[2*k]);
}*/
main(){

}
