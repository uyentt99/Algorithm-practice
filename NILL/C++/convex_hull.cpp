#include <bits/stdc++.h>
#define Fu(i,a,b) for(int i=(a); i<=(b); i++)
#define Fd(i,a,b) for(int i=(a); i>=(b); i--)
#define pb push_back
#define pob pop_back
using namespace std;
typedef long long LL;
void pre(){
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
}
const int N = 2e5 + 1;
int n, a[N];
LL sum[N], ans, dans;
struct Line {
    LL a, b, get(LL x) { return a * x + b; }
};
//________________convexhull____________________
/* vo'i he so goc tang dan_____vi tri' bai ki`->du`ng chat nhi phan
   truong hop he so goc gia?m chuyen a*x=(-a)*(-x) de co' he so goc tang .-.*/
struct ConvexHull {
    Line hull[N];
    int top;
    bool is_bad(int now, int trc, int sau) {
        Line c = hull[now], p = hull[trc], n = hull[sau];
        return (c.b - n.b)*(c.a - p.a) <=(p.b - c.b)*(n.a - c.a);
    }
    void add_line(LL a, LL b) {
        hull[++top] = {a,b};
        while (top> 2 && is_bad(top-1, top-2, top))
            hull[top-1] = hull[top], top--;
    }

    LL query(int x) {
        int l = 1, r = top;
        while (l<r) {
            int mid = (l + r) / 2;
            if (hull[mid].get(x) <= hull[mid + 1].get(x)) l = mid+1;
            else r = mid;
        }
        return hull[r].get(x);
    }
};
ConvexHull hull;
//
main() {
    pre();
}
