#include <bits/stdc++.h>
#define task "a"
#define Fu(i,a,b) for(int i=(a); i<=(b); ++i)
#define Fd(i,a,b) for(int i=(a); i>=(b); --i)
using namespace std;
typedef long long LL;
template <typename T> inline void Read(T &x){
    x=0;
    char c;
    while (!isdigit(c=getchar()));
    do{x=x*10+c-'0';} while (isdigit(c=getchar()));
}
template <typename T> inline void Write(T x){
    if (x>9) Write(x/10);
    putchar(x%10+48);
}
string Readstring(){
    string s=""; char c;
    while ( (c=getchar())==' ' || c=='\n');
    do { s+=c; } while ( (c=getchar())!=' ' && c!='\n');
    return s;
}
void Writestring(string s){ Fu(i,0,s.length()-1) putchar(s[i]);}
void pre(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
//
int a[100];
main(){
    pre();

}

