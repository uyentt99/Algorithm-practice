#include<bits/stdc++.h>
#include<conio.h>
#define ii pair<int, pair<int, int> > 
#define mp make_pair 
using namespace std; 
int t, n, m;
ii d[1000000];
int type[1000000];
int kq ;
ii st[1000000];
ii st1[1000000];
int top ;
int nn ;
int CCW( ii a , ii b ,ii c ){
	int abf = b.first - a.first ;
	int abs = b.second.first - a.second.first ;
	int bcf = c.first - b.first ;
	int bcs = c.second.first - b.second.first ;
	long long s = (long long)(abf) *bcs - (long long)(abs)*bcf ;
	if (s > 0 ) return 1 ;
	if (s == 0 ) return 0 ;
	return -1 ;
}
bool check_conver(ii a , ii b , ii c, ii d){
	pair <double,double > v1 , v2 ,v12 , v21 ;
	v1.first = b.first - a.first ;
	v1.second = b.second.first - a.second.first;

	v2.first = d.first - c.first;
	v2.second = d.second.first - c.second.first;

	v12.first = c.first - a.first ;
	v12.second = c.second.first - a.second.first;
	//if (v1.first / v2.first == v1.second/ v2.second ) return false ;
	double cos1 = ( v1.first* v12.first + v1.second* v12.second);
	cos1 = cos1 / ( sqrt(pow(v1.first,2) + pow(v1.second,2))* sqrt(pow(v12.first,2)+ pow(v12.second,2)));

	v21.first = -v12.first ;
	v21.second = -v12.second ;
	double cos2 = ( v2.first* v21.first + v2.second*v21.second);
	cos2 = cos2 / ( sqrt(pow(v2.first,2) + pow(v2.second,2)) *sqrt(pow(v21.first,2)+ pow(v21.second,2)));

	double g1 = acos(cos1);
	double g2 = acos(cos2);
	if (g1 + g2 < acos(-1) && g1+ g2 > 0) return true ;
	return false ;

}

void process(){
	sort(d,d+nn);
	if (n == 0 ) {
		cout<< 3 << endl;
		return ;
	}
	/*if (nn > 2){
	int  ij;
	for (ij = 2 ; ij < nn ; ij++)
	if ( CCW(d[ij-2] , d[ij-1], d[ij] ) != 0 )
	break ;
	if (ij == nn) {
	if (d[0].second.second == 1 && d[nn-1].second.second == 1)
	cout << 3<< endl ;
	else cout << 2 << endl ;
	return ;
	}
	}*/
	top = 2;
	st[1] = d[0] ;
	st[2] = d[1];
	for (int i = 2 ; i <nn ; i ++){
		while (top > 1 && CCW(st[top-1] , st[top], d[i]) > 0 ) top -- ;
		top ++ ;
		st[top] = d[i];
	}
	for (int i = nn-2 ;i >= 0 ; i--){
		while (top >1 && CCW(st[top-1] , st[top] ,d[i] )>0  ) top --;
		top ++;
		st[top] = d[i];
	}
	bool check1 = true, check2 = true ;
	for (int i= 1 ; i <= top ; i++){
		//cout << st[i].first << " " << st[i].second.first << endl;
		if (st[i].second.second == 0 ) check1 = false ;
		else check2 = false ;
	}
	if (check1) {
		cout << 3 << endl ;
		return ;
	}
	if (check2) {
		cout << 0 << endl ;
		return ;
	}
	int tmp = 1;
	while (tmp < top && st[top] == st[tmp]) {
		top -- ;
		tmp++;
	}

	for (int i= 1 ; i <= top ; i++){
		st[top+i] = st[i] ;
	}
	top*=2 ;
	int l = 0 ;
	int r = 0 ;

	for (int i = 1; i <= top ; i++){
		if (st[i].second.second == 0 ){
			if (l == 0 ) l = i ;
			r = i ;
		} else {
			if (l >1 && check_conver(st[l], st[l-1], st[r], st[r+1] )) {
				cout << 1 << endl ;
				return ;
			}
			l = 0 ;
		}
	}
	if (top > 2){
		while ( st[top].second.second == 0 && top > 0) top -- ;
		st1[1] = st[1];
		st1[2] = st[2];
		int top1 = 2 ;
		for (int i = 3; i <= top ; i++)
			if ( CCW(st1[top1], st1[top1-1] ,st[i] )==0) st1[top1] = st[i] ;
			else st1[++top1] = st[i];
			for (int i = 1 ; i <= top1 ; i++)
				if (st1[i].second.second == 0) {
					cout << 2 << endl ;
					return ;
				}
			cout << 3 << endl ;
			return;

	}
	cout << 2 << endl;

}

void readInput(){
	freopen("police.inp", "r" , stdin);
	freopen("police.out", "w" ,stdout);
	cin >> t ;
	int u ,v ;
	for (int jj = 0 ; jj < t ; jj++){
		cin >> n >> m ;

		for (int i = 0 ; i < n ; i++){
			cin >> u >> v;
			d[i] = mp(u,mp(v,0));
		}
		nn = n ;
		for (int i = 0 ; i < m ; i++){
			cin >> u >> v;
			d[nn] = mp(u,mp(v,1));
			nn++;
		}
		kq = -1 ;
		process() ;
	}
}
int main(){
	//check_conver(mp(1,mp(1,0)), mp(0,mp(0,0)), mp(1,mp(2,0)) , mp(0,mp(3,0)));
	readInput();
	//getch();
}



