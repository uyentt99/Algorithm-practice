#include <bits/stdc++.h>
#define task "TFOSS"
using namespace std;
typedef long long LL;
void pre(){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
//
const int N = 5e5;
//__________________toa do________________________________
struct td{
    int x, y;
    bool operator < (const td &b )const{
        return (x<b.x) || (x==b.x && y<b.y);
    }
    bool operator == (const td &b )const{
        return x==b.x && y==b.y;
    }
};
//_____________________________________________________________
LL sqr(int x) {return LL(x)*x;}
LL kc(td a, td b){
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
//
int n, T;
td d[N];
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pre();
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>d[i].x>>d[i].y;
        LL dmaxx = 0;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                dmaxx = max(dmaxx, kc(d[i],d[j]));
        cout<<dmaxx<<"\n";
    }
}
