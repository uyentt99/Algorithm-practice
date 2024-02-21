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
struct td{
    int x, y;
    bool operator < (const td &b )const{
        return (x<b.x) || (x==b.x && y<b.y);
    }
    bool operator == (const td &b )const{
        return x==b.x && y==b.y;
    }
};
td d[N];
//_______________________TICHCHEO__________________________
LL tcok(td a, td b, td c){
    td ab, bc;
    ab.x=b.x-a.x; ab.y=b.y-a.y;
    bc.x=c.x-b.x; bc.y=c.y-b.y;
    LL s = LL(ab.x)*bc.y - LL(bc.x)*ab.y;
    return s;
}
//_______________________BAOLOI____________________________
struct convexHull{
    td q[N];
    int top;
    int vtMaxx;
    int vt1, vt2;
    /*neu tim it dinh nhat thay > bang >=*/
    void convex(int n, td* d){
        top=1;
        q[1] = d[1];
        for(int i=2; i<=n; ++i) {
            while (top>1 && ( tcok(q[top-1],q[top],d[i])>=0) ) top--;
            q[++top] = d[i];
        }
        vtMaxx = top;
        for(int i=n-1; i>=1; --i) {
            while (top>vtMaxx && ( tcok(q[top-1],q[top],d[i])>=0) ) top--;
            q[++top] = d[i];
        }
    }
    //
    bool check(td q1, td a,td q2){
        LL w = tcok(q1,a,q2);
        if (w<0) return true;
        if (w==0){
            int miny = min(q1.y,q2.y);
            int maxy = max(q1.y,q2.y);
            if (a.y<miny || a.y>maxy) return true;
        }
        return false;
    }
    //
    bool inConvex(td a){
        if (a.x<q[1].x || a.x>q[vtMaxx].x) return false;

        while (vt1<vtMaxx && a.x >= q[vt1].x ) vt1++;
        if (check(q[vt1-1],a,q[vt1])) return false;

        while (vt2>vtMaxx && a.x >= q[vt2].x ) vt2--;
        if (check(q[vt2],a,q[vt2+1])) return false;

        return true;
    }
} myConvex;
//
pair<td,int> tdQuest[N];
int n, T;
bool kq[N];
void readInput(){
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>d[i].x>>d[i].y;
    cin>>T;
    for(int t=1; t<=T; ++t){
        td a;
        cin>>a.x>>a.y;
        tdQuest[t] = make_pair(a,t);
    }
}
//
int main(){
    pre();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    readInput();
    if (n==1) {
        for(int t=1; t<=T; ++t)
            if (tdQuest[t].first==d[1]) cout<<"YES\n";
            else cout<<"NO\n";
    }else{
        sort(d+1,d+n+1);
        myConvex.convex(n,d);
        myConvex.vt1 = 1;
        myConvex.vt2 = myConvex.top;

        sort(tdQuest+1,tdQuest+T+1);
        for(int t=1; t<=T; ++t)
            kq[tdQuest[t].second] = myConvex.inConvex(tdQuest[t].first);

        for(int t=1; t<=T; ++t)
            if (kq[t]) cout<<"YES\n";
            else cout<<"NO\n";
    }
}
