/*
    -tich cheo
    -bao loi
*/
#include <bits/stdc++.h>
#define Fu(i,a,b) for( int i=(a); i<=(b); i++)
#define Fd(i,a,b) for( int i=(a); i>=(b); i--)
using namespace std;
struct td{
    int x, y;
    bool operator < (const td &b )const{ return (x<b.x) || (x==b.x && y<b.y); }
};
typedef long long LL;
const int N = 5e5;
td q[N], d[N];
int n, m, t;
//
void pre(){
    freopen( "a.inp", "r", stdin);
    freopen( "a.out", "w", stdout);
}
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
    int top=2;
    q[1] = d[1]; q[2] = d[2];
    Fu(i,3,n) {
        while (top>1 && ( tcok(q[top-1],q[top],d[i])>0) ) top--;
        q[++top] = d[i];
    }
    Fd(i,n-1,1){
        while (top>1 && ( tcok(q[top-1],q[top],d[i])>0) ) top--;
        q[++top] = d[i];
    }
    return top;
}
//
main(){
    pre();
}
