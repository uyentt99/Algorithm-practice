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
struct Point{
    int x, y;
    bool operator < (const Point &b )const{
        return (x<b.x) || (x==b.x && y<b.y);
    }
    bool operator == (const Point &b )const{
        return x==b.x && y==b.y;
    }
};
//_______________________TICHCHEO__________________________
LL crossProduct(Point a,Point b,Point c){
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
} myConvex;
//___________________________________________________________
LL sqr(int x) {return LL(x)*x;}
LL kc(int i, int j){
   Point a = myConvex.q[i];
   Point b = myConvex.q[j];
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
//
int nextVt(int i) {return i%myConvex.top+1; }
int n, T;
Point d[N];
int main(){
	pre();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>d[i].x>>d[i].y;
		//tim bao loi
        sort(d+1,d+1+n);
        myConvex.convex(n,d);
		//tim khoang cach loi nhat
        int j = 1;
        LL dmaxx = 0;
        for(int i=1; i<myConvex.top; ++i){
			// j chay tren bao loi
            while (kc(i,j) < kc(i,nextVt(j)))
                j = nextVt(j);
			//dinh j la dinh xa dinh i nhat
            dmaxx = max(dmaxx, kc(i,j));
        }
        cout<<dmaxx<<"\n";
    }
}
