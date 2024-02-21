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
//__________________toa do________________________________
struct Point{
    int x, y;
    bool operator < (const Point &b )const{
        return (x<b.x) || (x==b.x && y<b.y);
    }
    bool operator == (const Point &b )const{
        return x==b.x && y==b.y;
    }
} d[N];
//_______________________TICHCHEO__________________________
LL crossProduct(Point a, Point b, Point c){
    Point ab, bc;
    ab.x=b.x-a.x; ab.y=b.y-a.y;
    bc.x=c.x-b.x; bc.y=c.y-b.y;
    LL s = LL(ab.x)*bc.y - LL(bc.x)*ab.y;
    return s;
}
//_______________________BAOLOI____________________________
struct convexHull{
    Point q[N];
    int top;
    int vtMaxx;
    /*neu tim it dinh nhat thay > bang >=*/
    void convex(int n, const Point* d){
        top=1;
        q[1] = d[1];
        for(int i=2; i<=n; ++i) {
            while (top>1 && ( crossProduct(q[top-1],q[top],d[i])>=0) ) top--;
            q[++top] = d[i];
        }
        vtMaxx = top;
        for(int i=n-1; i>=1; --i) {
            while (top>vtMaxx && ( crossProduct(q[top-1],q[top],d[i])>=0) ) top--;
            q[++top] = d[i];
        }
    }
    //
    int vtGiaoTren(int x) {
        int l = 1, r = vtMaxx;
        while (l<r) {
            int mid = (l+r) / 2;
            if (x<=q[mid].x) r = mid;
            else l = mid+1;
        }
        if (l==1) return 2;
        return l;
    }
    //
    int vtGiaoDuoi(int x) {
        int l = vtMaxx, r = top;
        while (l<r) {
            int mid = (l+r+1) / 2;
            if (x<=q[mid].x) l = mid;
            else r = mid-1;
        }
        if (l==top) return top-1;
        return l;
    }
    //
    bool check(Point q1, Point a,Point q2){
        LL w = crossProduct(q1,a,q2);
        if (w<0) return true;
        if (w==0){
            int miny = min(q1.y,q2.y);
            int maxy = max(q1.y,q2.y);
            if (a.y<miny || a.y>maxy) return true;
        }
        return false;
    }
    bool inConvex(Point a){
        if (a.x<q[1].x || a.x>q[vtMaxx].x) return false;
        int cat;
		//kiem tra vi tri diem a voi vi tri cat bao tren
        cat = vtGiaoTren(a.x);
        if (check(q[cat-1],a,q[cat])) return false;
		//kiem tra vi tri diem a voi vi tri cat bao tren
        cat = vtGiaoDuoi(a.x);
        if (check(q[cat],a,q[cat+1])) return false;

        return true;
    }
} myConvex;
//
void specialCase(){
    int T;
    cin>>T;
    for(int t=1; t<=T; ++t){
        Point a;
        cin>>a.x>>a.y;
        if (a==d[1]) cout<<"YES\n";
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
    if (n==1) specialCase();
    else{
		//tim bao loi
        sort(d+1,d+n+1);
        myConvex.convex(n,d);
       // t truy van kiem tra dinh co thuoc do thi ko
        int T;
        cin>>T;
        for(int t=1; t<=T; ++t){
            Point a;
            cin>>a.x>>a.y;
            if (myConvex.inConvex(a)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
