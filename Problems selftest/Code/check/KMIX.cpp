#include <bits/stdc++.h>
#define task "KMIX"
using namespace std;
typedef long long LL;
void pre(){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
//
const int N = 5e5;
struct td{
    int x, y;
    bool operator < (const td &b )const{ return (x<b.x) || (x==b.x && y<b.y); }
};
//
td q[N], d[N];
//_______________________TICHCHEO____________________________
LL tcok(td a, td b, td c){
    td ab, bc;
    ab.x=b.x-a.x; ab.y=b.y-a.y;
    bc.x=c.x-b.x; bc.y=c.y-b.y;
    LL s = LL(ab.x)*bc.y - LL(bc.x)*ab.y;
    return s;
}
//_______________________BAOLOI_______________________________
/*tim bao loi gom nhieu dinh nhat (top) dinh luu vao mang q,
     neu tim it dinh nhat thay > bang >= -->sai truong hop tam giac*/
int convex(int n){
    int top=1;
    q[1] = d[1];
    for(int i=2; i<=n; ++i) {
        while (top>1 && ( tcok(q[top-1],q[top],d[i])>=0) ) top--;
        q[++top] = d[i];
    }
    int vtMaxx = top;
    for(int i=n-1; i>=1; --i) {
        while (top>vtMaxx && ( tcok(q[top-1],q[top],d[i])>=0) ) top--;
        q[++top] = d[i];
    }
    return top;
}
//
void specialCase(){
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        td a;
        cin>>a.x>>a.y;
        if (a.x==d[1].x && a.y==d[1].y) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
//
int main(){
    pre();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>d[i].x>>d[i].y;

    sort(d+1,d+n+1);
    int m = convex(n);
    if (n==1) specialCase();
    else {
        LL s = 0;
        for(int i = 2; i<=m; ++i)
            s = s + LL(q[i].x - q[i-1].x)*(q[i].y + q[i-1].y);
            s = abs(s);

        int T;
        cin>>T;
        for(int t=1; t<=T; ++t){
            td a;
            cin>>a.x>>a.y;
            LL w = 0;
            for(int i = 2; i<=m; ++i)
                w = w + abs(tcok(a,q[i],q[i-1]));
            if (w==s){
                if (s==0) {
                    int miny = min(q[1].y,q[2].y);
                    int maxy = max(q[1].y,q[2].y);
                    if (a.y<miny || a.y>maxy) cout<<"NO\n";
                    else cout<<"YES\n";
                }else cout<<"YES\n";
            }else cout<<"NO\n";
        }
    }
}
