/*
    - KMP
    - Z aglo
    - Manacher
    - Trie
*/
#include <bits/stdc++.h>
#define Fu(i,a,b) for( int i=(a); i<=(b); i++)
#define Fd(i,a,b) for( int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;
const int N=3e5+10;
char a[N], s[N];
//
void pre(){
    freopen( "a.inp", "r", stdin);
    freopen( "a.out", "w", stdout);
}
//______________________KMP___________________________
int f[N], g[N];
void fcalc(int n){
    f[0] = 0;
    int j= 0;
    Fu(i,1,n-1){
        while (j>0 && s[i]!=s[j]) j=f[j-1];
        if (s[i]!=s[j]) f[i]=0; else f[i]=++j;
    }
}
//
void gcalc(int m, int n){
    g[0] = (s[0]==a[0]);
    int j=g[0];
    Fu( i,1,m-1){
        if (j==n) j=f[j-1];
        while (j>0 && a[i]!=s[j]) j=f[j-1];
        if (a[i]!=s[j]) g[i]=0; else g[i]=++j;
    }
}
//______________________Z aglo________________________
int z[N];
void zalgo(int n){
    int l,r=-1;
    z[0]=n;
    Fu(i,1,n-1){
        if (i>r){
            l=r=i;
            while (r<n && s[r]==s[r-i]) r++;
            z[i]=r-l; r--;
        } else{
            int j=i-l;
            if (i+z[j]-1<r) z[i]=z[j];
            else{
                l=i;
                while (r<n && s[r]==s[r-i]) r++;
                z[i]=r-l; r--;
            }

        }
    }
}
//______________________Manccher___________________________
//int f[N];
string x;
void manacher(int n) {
    int res=0;
    string s="#";
    Fu(i,0,n-1) s+=x[i], s+='#';
    int m=2*n+1,l, r, d;
    l=r=-1;
    Fu(i,0,m-1) {
        if (i<=r) d=min(f[l+r-i], r-i);
        else d=0;
        while (i-d>0 && i+d+1<m & s[i-d-1]==s[i+d+1]) d++;
        f[i]=d;
        if (i+d>r) l=i-d, r=i+d;
        res=max(res,d);
    }
    cout<<res;
}
//______________________TRIE________________________________
const int slcon=27;
//const int BASE=1337377;
struct Trienode{
    Trienode* child[slcon];
    int l;
    bool isleaf;
};
typedef Trienode* Tnode;
Tnode head;
//LL f[N];
//
Tnode newnode(){
    Tnode node=new(Trienode);
    Fu(i,0,26) node->child[i]=NULL;
    node->isleaf=0;
    return node;
}
//
void creat(){
    scanf("%s", a);
    Tnode c=head;
    Fu(i,0,strlen(a)-1){
        int x=a[i]-'a';
        if (c->child[x]==NULL) c->child[x]=newnode();
        c = c->child[x];
    }
    c->isleaf=1;
    c->l=strlen(a);
}
//
void solve(int m){
//    f[m+1]=1;
    Fd(i,m,0){
        Tnode c=head;
        Fu(j,i,m){
            int x=s[j]-'a';
            c=c->child[x];
            if (c==NULL) break;
           // if (c->isleaf) f[i]=(f[i]+f[i+c->l])%BASE;
        }
    }
//    printf("%lld", f[0]);
}
//
void Trie(){
    head=newnode();
    scanf("%s",s);
    int n; scanf("%d",&n);
    Fu(i,1,n) creat();
    solve(strlen(s)-1);
}
//________________________________________________________
main(){
    pre();
}
