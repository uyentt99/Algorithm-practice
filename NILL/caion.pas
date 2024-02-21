********************************************************************************************************************************
[PHAN TICH SO                          ]
[SO LON                                ]
[DOI VE NHI PHAN                       ]
[HEAP-DIJKSTRA HEAP                    ]
[INTERVANTREE                          ]
[TIM TAM DUONG TRON NGOAI TIEP TAM GIAC]
[BAO LOI                 -CONVEX       ]
[DIEN TICH DA GIAC                     ]
[TRASH                                 ]  
[PHUONG TRINH DIOPLANTINE              ]
[NUMPASS                               ]
[CAU                                   ]
[LUONG                                 ]
[CAP GHEP                              ]
********************************************************************************************************************************
CO HUONG X1*X2+Y1*Y2
VO HUONG X1*Y2-Y1*X2
{phan tich so}
-->procedure sangnt;
var     i,j:longint;
begin
        for i:=2 to n do p[i]:=-1;
        m:=0;
        for i:=2 to round(sqrt(n)) do
          if p[i]=-1 then
           for j:=i to n div i do p[i*j]:=i;
end;
            while p[j]<>-1 dobegin
                x:=p[j];
                a[x]:=a[x]+1;
                j:=j div x;
                end;
                a[j]:=a[j]+1;
********************************************************************************************************************************
{ SO LON }
function tong(a,b:gt):gt;
var     i,j,r:longint;
        s:gt;
begin
        while length(a)<length(b) do a:='0'+a;
        while length(b)<length(a) do b:='0'+b;
        r:=0;
        s:='';
        for i:=length(a) downto 1 do
           begin
                r:=r+ord(a[i])+ord(b[i])-96;
                s:=chr( r mod 10 +48)+ s;
                r:=r div 10;
           end;
        if r>0 then s:='1'+s;
        exit(s);
end;
//
function hieu(a,b:gt):gt;
var i,j,r:longint;
        s:gt;
begin
       while length(b)<length(a) do b:='0'+b;
       r:=0;
       for i:=length(a) downto 1 do
            begin
                 r:=10-r+ord(a[i])-ord(b[i]);
                 s:=chr( r mod 10+48)+s;
                 r:=1-r div 10
            end;
       while (length(s)>1) and (s[1]='0') do delete(s,1,1);
       exit(s);
end;
//
function tichnho(a:gt;b:longint):gt;
var i,r:longint;
    s,x:gt;
begin
       r:=0;
       s:='';
       for i:=length(a) downto 1 do
         begin
              r:=r+b*( ord(a[i])-48 );
              s:=chr( r mod 10+48) +s;
              r:=r div 10;
         end;
       if r>0 then
          begin
               str(r,x); s:=x+s;
          end;
       exit(s);
end;
//
function tich(a,b:gt):gt;
var    i,j,r,base:longint;
       s,st:gt;
begin
       base:=0;
       st:='';
       for i:=length(b) downto 1 do
          begin
               st:=tichnho(a,ord(b[i])-48);
               for j:=1 to base do st:=st+'0';
               s:=tong(s,st);
               base:=base+1;
          end;
       exit(s);
end;
//
********************************************************************************************************************************
{ DOI NHI PHAN}
procedure chia(var a:so;var d:longint);
var   i:longint;
begin
      d:=0;
      for i:=1 to a[0] do
        begin
             d:=d*10+a[i];
             a[i]:=d div 2;
             d:=d mod 2;
        end;
      if (a[0]>1) and (a[1]=0) then
         begin
              a[0]:=a[0]-1;
              for i:=1 to a[0] do a[i]:=a[i+1];
         end;
end;
//
procedure change(a:so;var x:so);
var   h:longint;
begin
      h:=0;
      while not kt(a) do
         begin
              h:=h+1;
              chia(a,x[h]);
         end;
      x[0]:=h;
end;
//
procedure Nhan(var kq: So; d: longint);
var   i,t: integer;
begin
     t:=0;
     for i:=kq[0] downto 1 do
       begin
           t:=kq[i]*2+t;
           kq[i]:=t mod 10;
           t:=t div 10;
       end;
     if t>0 then
      begin
           kq[0]:=kq[0]+1;
           for i:=kq[0] downto 1 do kq[i]:=kq[i-1];
           kq[1]:=t;
      end;
     if d=1 then inc(kq[kq[0]])
end;
//
*******************************************************************************************************************************
{ HEAP} THUONG
//
procedure upheap(i:longint);
var p,x:longint;
begin
     x:=a[i];
     repeat
          p:=i div 2;
          if (p=0) or (a[p]>=x) then break;
          a[i]:=a[p];
          i:=p;
     until false;
     a[i]:=x;
end;
//
procedure downheap(i:longint);
var x,c:longint;
begin
      x:=a[i];
      repeat
            c:=i*2;
            if (c<m) and (a[c]<a[c+1]) then inc(c);
            if (c>m) or (a[c]<=x) then break;
            a[i]:=a[c];
            i:=c;
      until false;
      a[i]:=x;
end;
//
********************************************************************************************************************************
{ DIJKSTRA HEAP }
-------------------POS-ITEMS----------------------------------------------------------------------------------------------------
procedure downheap(i:longint);
var r,c:longint;
begin
     r:=pos[i];
     repeat
           c:=r*2;
           if (c<k) and (d[items[c]]>d[items[c+1]])then inc(c);
           if (c>k) or (d[items[c]]>=d[i]) then break;
           items[r]:=items[c];
           pos[items[c]]:=r;
           r:=c;
      until false;
      items[r]:=i;
      pos[i]:=r;
end;
//
procedure upheap(i:longint);
var r,c:longint;
begin
    c:=pos[i];
    repeat
         r:=c div 2;
         if (r=0) or (d[items[r]]<=d[i]) then break;
         items[c]:=items[r];
         pos[items[r]]:=c;
         c:=r;
    until false;
    items[c]:=i;
    pos[i]:=c;
end;
-------------------KIEUMOI------------------------------------------------------------------------------------------------------
procedure insert(u,x:longint);
var   r,c:longint;
begin
      top:=top+1;
      r:=top;
      repeat
            c:=r div 2;
            if (c<1) or (h[c].d<d[u,x]) then break;
            h[r]:=h[c];
            r:=c;
      until false;
      h[r].d:=d[u,x];
      h[r].u:=u;
      h[r].x:=x;
end;
//
procedure downheap(i:longint);
var   r,c,u,v:longint;
      x:kieu;
begin
        c:=i;
        x:=h[1];
        repeat
             r:=c*2;
             if (r<top) and (h[r+1].d<h[r].d) then r:=r+1;
             if (r>top) or (h[r].d>x.d) then  break;
             h[c]:=h[r];
             c:=r;
        until false;
        h[c]:=x;
end;

********************************************************************************************************************************
{INTERVAL TREE}--> TIM MAX
// mang 4*n
FUNCTION cay(i,l,r:longint):longint;
var   x,maxtrai,maxphai:longint;
begin
        if l=r then
             begin
                  f[i]:=gt[l];
                  exit(f[i]);
             end;
        x:=(l+r) div 2;
        maxtrai:=cay(i*2,l,x);
        maxphai:=cay(i*2+1,x+1,r);
        f[i]:= max( maxtrai,maxphai ) ;
        exit(f[i]);
end;
//
FUNCTION timmax(i,l,r,a,b:longint):longint;
var  x:longint;
     trai,phai:longint;
begin
       if (b<l) or (r<a) then exit(0);
       if (a<=l) and  (r<=b) then exit(f[i]);
       x:=(l+r) div 2;
       trai:=timmax( i*2,l,x,a,b);
       phai:=timmax(i*2+1,x+1,r,a,b);
       exit(max( trai,phai ) );
end;
//
********************************************************************************************************************************
{ TAM DUONG TRON NGOAI TIEP TAM GIAC}
PROCEDURE giao(d1,d2:dt);
var   o:toado;
      d,dx,dy:real;
begin
      d:=d1.a*d2.b-d2.a*d1.b;
      dx:=d1.c*d2.b-d2.c*d1.b;
      dy:=d1.a*d2.c-d2.a*d1.c;
      o.x:=dx/d;
      o.y:=dy/d;
      write(f2,o.x:0:5,' ',o.y:0:5);
end;
//
FUNCTION duongtt(a,b:point):dt;
var  m:toado;
     d:dt;
begin
     m.x:=(a.x+b.x)/2;
     m.y:=(a.y+b.y)/2;
     d.a:=a.x-b.x;
     d.b:=a.y-b.y;
     d.c:=d.a*m.x+d.b*m.y;
     exit(d);
end;
//
PROCEDURE timtam(a,b,c:point);
var d1,d2:dt;
begin
     d1:=duongtt(a,b);
     d2:=duongtt(b,c);
     giao(d1,d2);
end;
********************************************************************************************************************************
{ BAO LOI}-CONVEX
FUNCTION kt(a,b:td):boolean;
begin
      if a.x<b.x then exit(true);
      if a.x>b.x then exit(false);
      if a.y<b.y then exit(true);
      exit(false);
end;
//
PROCEDURE sort(l,r:longint);
var   i,j:longint;
      x,tg:td;
begin
      i:=l;
      j:=r;
      x:=p[(l+r) div 2];
      while i<=j do
         begin
              while kt(p[i],x) do i:=i+1;
              while kt(x,p[j]) do j:=j-1;
              if i<=j then
                 begin
                      tg:=p[i]; p[i]:=p[j]; p[j]:=tg;
                      i:=i+1; j:=j-1;
                 end;
         end;
      if i<r then sort(i,r);
      if l<j then sort(l,j);
end;
//
FUNCTION ok(a,b,c:td):int64;
var  t:int64;
     va,vb:td;
begin
      vb.x:=a.x-b.x; vb.y:=a.y-b.y;
      va.x:=c.x-b.x; va.y:=c.y-b.y;
      t:=va.x*vb.y - va.y*vb.x;
      exit(t);
end;
//
PROCEDURE tim;
var  i:longint;
begin
     m:=2;
     q[1]:=p[1];
     q[2]:=p[2];
     for i:=3 to n do
        begin
             while (m>1) and (ok(q[m],q[m-1],p[i]) <0)
                 do m:=m-1;
             m:=m+1;
             q[m]:=p[i];
        end;

     for i:=n-1 downto 1 do
        begin
             while (m>1) and (ok(q[m],q[m-1],p[i]) <0)
                 do m:=m-1;
             m:=m+1;
             q[m]:=p[i];
        end;
end;
-------------------THEM----------------------------------------------------------------------------------------------------------
//
FUNCTION gcd(a,b:longint):longint;
begin
       if a=0 then exit(b);
       exit( gcd(b mod a,a));
end;
//
PROCEDURE tinhb;
var  i:longint;
     u,v:longint;
begin
     b:=0;
     for i:=1 to m do
        begin
             u:=abs(q[i].x-q[i+1].x);
             v:=abs(q[i].y-q[i+1].y);
             b:=b+gcd(u,v);
        end;
end;
//
PROCEDURE  tinhs;

var   i:longint;
begin
     s:=0;
     for i:=2 to m-1 do
       s:=s+abs(ok(q[i],q[1],q[i+1]));
     s:=s div 2;
end;

********************************************************************************************************************************
{ DIEN TICH DA GIAC LOI LOM}
for i:=1 to n do s:=s+(d[i-1,1]-d[i+1,1])*d[i,2];
1 la x 2 la y
********************************************************************************************************************************
{TRASH- THAY THUAN}
PROCEDURE xuli;
var
     i,j:longint;
     t1,t2,kc:longint;
     h:real;
begin
     p[0]:=p[n];
     vt[0] := 1;
     for i := 1 to n do
       begin
            vt[i] := vt[i-1];
            t1 := abs( ok(p[i],p[i-1],p[ vt[i] ]) );
            t2 := abs( ok(p[i],p[i-1],p[ vt[i]+1 ]) );
            while (t1 <= t2) and (vt[i] < n+i-2) do
              begin
                   vt[i] := vt[i]+1;
                   t1    := t2;
                   t2    := ok(p[i],p[i-1],p[ vt[i]+1 ]);
                   t2:=abs(t2);
              end;
            kc:= sqr( p[i].x-p[i-1].x ) + sqr( p[i].y-p[i-1].y );
            h:=t1/sqrt(kc);
            if k>h then k:=h;
        end;
end;
//
PROCEDURE conver;
var  k,i,m,x,j:longint;
begin
     k:=1;
     for i:=2 to n do
         if (q[k].x=q[i].x) and (q[k].y<q[i].y) then k:=i
         else if q[k].x>q[i].x then k:=i;
     q[0]:=q[n]; q[n+1]:=q[1];
     if ok(q[k-1],q[k],q[k+1])>0 then x:=-1 else x:=1;
     m:=1;
     p[m]:=q[k];
     for j:=k+1 to n+k do
        begin
             i:=(j-1) mod n+1;
             while (m>1) and (ok(p[m],p[m-1],q[i])*x <0)
                 do m:=m-1;
             m:=m+1;
             p[m]:=q[i];
        end;
     n:=m-1;
end;
********************************************************************************************************************************
{DIOPLANTINE}
var
     a1,b1,a2,b2,d,p1,p2,c:int64;
     x1,x2:int64;
procedure Solve(a,b:int64;var x,y:int64);
var
  m, n, r, q, xm, xn, xr: int64;
begin
    m := a; xm := 1;
    n := b; xn := 0;
     while n <> 0 do
       begin
           q := m div n;
           r := m mod n;
           xr := xm - q * xn;
           m := n; xm := xn;
           n := r; xn := xr;
       end;
    d := m;
    x := xm;
    y := (d - a * xm) div b;
end;
begin
     readln(a1,b1,a2,b2);
     if a1>a2 then solve(a1,a2,x1,x2) else solve(a2,a1,x2,x1);
     p1 := a2 div d;
     p2 := a1 div d;
     c  := b2-b1;
     x1 := (x1*(c div d) mod p1+p1) mod p1;
     x2 := -(c-a1*x1) div a2;
     while (x1<0) or (x2<0) do
        begin
            x1 := x1+p1;
            x2 := x2+p2;
        end;
     write(x1,' ',x2);
end.

********************************************************************************************************************************
{NUMPASS}
function check(q,x,k:longint):longint;
var t:int64;
    r:longint;
begin
      t:=x;   r:=1;
      while q>0 do
        begin
             if (q and 1) =1 then r:=r*t mod k;
             t:=(t*t) mod k;
             q:=q shr 1;
        end;
      exit(r);
end;
//
function dux(q:longint):longint;
var   tx,ty,r:int64;
begin
      ty:=10;
      tx:=1;
      if (q and 1)=1 then r:=1 else r:=0;
      q:=q shr 1;
      while q>0 do
        begin
             tx:=(tx*ty+tx)  mod md;
             ty:=ty*ty mod md;
             if (q and 1)=1 then r:=(tx+r*ty) mod md;
             q:=q shr 1;
        end;
      exit(r);
end;
********************************************************************************************************************************
{TIM CAU}
PROCEDURE dfs(u:longint);
var    p:graph;
       v:longint;
begin
        time:=time+1;
        color[u]:=1;
        num[u]:=time; low[u]:=time;
        p:=g[u];
        while p<> nil do
          begin
               v:=p^.v;
               if color[v]=0 then
                  begin
                       tr[v].x:=u;
                       tr[v].s:=p^.s;
                       dfs(v);
                       low[u]:=min(low[v],low[u]);
                  end
               else if (color[v]=1) and (tr[u].x<>v) then low[u]:=min(low[u],low[v]);
               p:=p^.link;
          end;

        color[u]:=2;
        if (low[u]=num[u]) and (tr[u].x<>-1) then
           begin
                inc(count);
                c[ tr[u].s ].kt:=true;
           end;
end;

********************************************************************************************************************************
{LUONG}----------VOHUONG------------------------------------------
uses   math;
const  finp='luong.inp';
       fout='luong.out';

type   point=record
           x,y:longint;
           end;
       graph=^tnode;
       tnode=record
           v:longint;
           link:graph;
          end;

var    f1,f2:text;
       q,trace:array[0..10000] of longint;
       f,c:array[0..10000,0..10000] of longint;
       g:array[0..10000] of graph;
       free:array[0..10000] of boolean;
       dm:array[0..10000] of point;
       m,n,kq:longint;
//
procedure add(u,v:longint);
var p:graph;
begin
      new(p);
      p^.v:=v;
      p^.link:=g[u];
      g[u]:=p;
end;
//
procedure enter;
var  i,u,v:longint;
     p:graph;
begin
      assign(f1,finp); reset(f1);
      readln(f1,n,m);
      for i:=1 to m do
           begin
               readln(f1,u,v,c[u,v]);
               c[v,u]:=c[u,v];
               dm[i].x:=u;
               dm[i].y:=v;
               add(u,v);
               add(v,u);
           end;
      close(f1);
end;
//
function timduong:boolean;
var u,v,last,first:longint;
    p:graph;
begin
     fillchar(q,sizeof(q),0);
     fillchar(free,sizeof(free),true);
     first:=1;
     q[1]:=1;
     trace[1]:=0;
     last:=1;
     free[1]:=false;
     while first<= last do
         begin
              u:=q[first];
              p:=g[u];
              while p<> nil do
                begin
                   v:=p^.v;
                   if free[v] then
                    if (f[u,v]<c[u,v]) or (f[v,u]>0) then
                      begin
                           trace[v]:=u;
                           last:=last+1;
                           q[last]:=v;
                           free[v]:=false;
                           if v=n then exit(true)
                      end;
                   p:=p^.link;
                end;
              first:=first+1;
         end;
     exit(false);
end;
//
procedure tangluong;
var i,j,u,v,k:longint;
begin
      v:=n;
      u:=trace[n];
      k:=maxlongint;
      while v<>1 do
         begin
              if f[v,u]>0 then k:=min(k,f[v,u])
                 else k:=min(k,c[u,v]-f[u,v]);
              v:=u;
              u:=trace[v];
         end;
      v:=n;
      u:=trace[n];
      while v<>1 do
         begin
              if f[v,u]>0 then f[v,u]:=f[v,u]-k
                 else f[u,v]:=f[u,v]+k;
              v:=u;
              u:=trace[v];
         end;
      kq:=kq+k;
end;
//
procedure inkq;
var i,u,v:longint;
begin
      assign(f2,fout); rewrite(f2);
      writeln(f2,kq);
      for i:=1 to m do
         begin
              u:=dm[i].x;
              v:=dm[i].y;
              writeln(f2,u,' ',v,' ',f[u,v]-f[v,u]);
         end;
      close(f2);
end;
//
BEGIN
      enter;
      fillchar(f,sizeof(f),0);
      kq:=0;
      while timduong  do tangluong;
      inkq;
END.
********************************************************************************************************************************
uses    math;
const   finp='print.inp';
        fout='print.out';
var
        fi,fo:text;
        a:array[0..1001,0..1001] of boolean;
        x,y,q,tr:array[0..1001] of longint;
        n,i,j,u,v,m:longint;
//
procedure tv(u:longint);
var v:longint;
begin
     if u=0 then exit;
     v:=tr[u];
     y[u]:=v;
     tv(x[v]);
     x[v]:=u;
end;
//
procedure find(u:longint);
var i,j,d,c:longint;
begin
      d:=1;
      c:=1;
      q[1]:=u;
      fillchar(tr,sizeof(tr),0);
      while d<=c do
      begin
          u:=q[d];
          for i:=1 to n do
            if (tr[i]=0) and a[u,i] then
              begin
                 tr[i]:=u;
                 if y[i]<>0 then begin
                        inc(c);
                        q[c]:=y[i];
                        end
                    else begin
                             tv(i); exit;
                         end;
              end;
          d:=d+1;
      end;
end;
//
procedure capghep;
var  i,j,dem:longint;
begin
       fillchar(x,sizeof(x),0);
       fillchar(y,sizeof(y),0);
       dem:=0;
       for i:=1 to m do
          if x[i]=0 then find(i);
       j:=1;
       for i:=1 to m do
          if x[i]=0 then
          begin
               dem:=dem+1;
               while (j<=n) and (y[j]<>0) do j:=j+1;
               x[i]:=j;
               j:=j+1;
          end;
       writeln(fo,dem);
       for i:=1 to m do writeln(fo,x[i]);
end;
//
begin
        assign(fi,finp); reset(fi);
        assign(fo,fout); rewrite(fo);
        readln(fi,m,n);
        while not seekeof(fi) do
            begin
                readln(fi,u,v);
                a[u,v]:=true;
            end;
        capghep;
        close(fi);
        close(fo);
end.

