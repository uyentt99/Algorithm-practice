#include <bits/stdc++.h>
using namespace std;
#define fu(i,j,n) for(int i=j;i<=n;i++)
#define BASE 15111992
#define ll long long
#define matrix vector<vector<ll> >
matrix a,mr;
int m;
string f[55],s;
int c1,c2,mc1,mc2;
bool r[105],l1[105],l2[105];
//...........................................
matrix operator * (const matrix &a, const matrix &b){
    matrix c;
    c.resize(2);
    c[0].resize(2);
    c[1].resize(2);
    fu(i,0,1) fu(j,0,1) {
        c[i][j]=0;
        fu(k,0,1){
            c[i][j]+=(a[i][k]*b[k][j] %BASE);
            c[i][j]=c[i][j]%BASE;
        }
    }
    return c;
}
matrix power(int n){
    if (n==1) return a;
    matrix t=power(n/2);
    t=t*t;
    if (n %2==1) t=t*a;
    return t;
}
//...........................................
int tinh(int h){
    string st=f[h],x;
    int d=0;
    fu(i,0,st.length()-m)
        if (s==st.substr(i,m)) d++;
    return d;
}

void init(int d){
    string st=f[d];
    fu(i,1,m){
      r[i]=1;
      fu(j,0,i-1) if (s[m+j-i]!=st[j]) {r[i]=0; break;}
    }
    int h=st.length();
    fu(i,1,m){
      l1[i]=1;
      fu(j,0,i-1) if (s[j]!=st[h-i+j]) {l1[i]=0; break;}
    }
    st=f[d+1];
    h=st.length();
    fu(i,1,m){
      l2[i]=1;
      fu(j,0,i-1) if (s[j]!=st[h-i+j]) {l2[i]=0; break;}
    }
    c1=c2=0;
    fu(i,1,m) if (r[i]){
        if (l1[m-i]) c1++;
        if (l2[m-i]) c2++;
    }
    mc1=tinh(d);
    mc2=tinh(d+1);
}
//........................................................
void asd(int n){
     a.resize(2);
     a[0].resize(2);
     a[1].resize(2);
     a[0][0]=0;
     a[0][1]=a[1][0]=a[1][1]=1;
     matrix t=power(n-1);
     long long s,f0,f1,f2;
     f1=t[1][0];
     f2=t[1][1];
     f0=(f2-f1+BASE) %BASE;
     s= (mc1*f1) %BASE + (mc2*f2) %BASE;
     if (n%2==1) f2--; else f1--;
     s= s % BASE + (c2*f2) %BASE +(c1*f1) % BASE;
     s= s % BASE;
    // cout<<mc1<<" "<<mc2<<" "<<c1<<" "<<c2;
     cout<<s;
}

main(){
    //freopen("a.inp","r",stdin);
   // freopen("a.out","w",stdout);
    int n,d;
    cin>>n;
    cin>>f[1]>>f[2]>>s;
    m=s.length();
    for(d=2;d<=n;d++){
        f[d+1]=f[d]+f[d-1];
        if (f[d].length()>=m) break;
    }
    if (n<=d+1) cout<<tinh(n); else {init(d); asd(n-d);}
    //fu(i,1,m) cout<<"\n"<<r[i]<<" "<<l1[i]<<" "<<l2[i];
}
