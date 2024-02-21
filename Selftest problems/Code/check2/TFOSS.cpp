#include <bits/stdc++.h>
#define task "TFOSS"
using namespace std;
typedef long long LL;
void pre(){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
const int N = 1e5;
//__________________toa do________________________________
struct Point{
    int x, y;
    bool operator < (const Point &b )const{
        return (x<b.x) || (x==b.x && y<b.y);
    }
};
Point d[N], p0;
//
LL sqr(int x){ return LL(x)*x; }
LL distSq(Point p1, Point p2) {
    return sqr(p1.x - p2.x)+  sqr(p1.y - p2.y);
}
//______________hàm giúp xác định hướng___________________-
// = 0 thằng hàng, >0 ngược chiều, <0 thuận chiều
LL crossProduct(Point a, Point b, Point c){
    Point ab, bc;
    ab.x=b.x-a.x; ab.y=b.y-a.y;
    bc.x=c.x-b.x; bc.y=c.y-b.y;
    LL s = LL(ab.x)*bc.y - LL(bc.x)*ab.y;
    return s;
}
// tim diem duoi cung ben trai
void findP0(int n, Point d[]){
    p0 = d[1];
    for(int i=2; i<=n; ++i)
        if (p0<d[i]) p0 = d[i];
}
// ham de so sanh goc
 bool compare(Point p1, Point p2){
    LL o = crossProduct(p0, p1, p2);
    if (o == 0)
    return (distSq(p0, p1)) < distSq(p0, p2);
    return o>0;
}
//tim bao loi
//neu tim it dinh nhat thay > bang >=
// mảng q là 1 stack lưu các điểm thuộc bao lồi
Point q[N];
// top : số đỉnh trong stack
int top;
void convex(int n, Point d[]){
    findP0(n,d);
    sort(d+1,d+1+n,compare);
    top=1;
    q[1] = d[1];
    for(int i=2; i<=n; ++i) {
        // xoa dinh khi huong khong nguoc chieu kim dong ho
        while (top>1 && ( crossProduct(q[top-1],q[top],d[i])<=0) ) top--;
        q[++top] = d[i];
    }
}
//_________________________________________________________
LL kc(int i, int j){
    Point a = q[i];
    Point b = q[j];
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
int nextVt(int i) {return i%top+1; }
//
int main(){
    pre();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>d[i].x>>d[i].y;

        convex(n,d);

        int j = 1;
        LL dmaxx = 0;
        for(int i=1; i<top; ++i){
            while (kc(i,j) < kc(i,nextVt(j)))
                j = nextVt(j);
            dmaxx = max(dmaxx, kc(i,j));
        }
        cout<<dmaxx<<"\n";
    }
}
