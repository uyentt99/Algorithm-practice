string tong(string a,string b){
    int i,r=0,l1=a.length(),l2=b.length();
    string s="";
    if (l1>l2) {b.insert(0, l1-l2,'0');}
    else { a.insert(0, l2-l1, '0');}
    int l=a.length();
    for (i=l-1;i>=0;i--){
        r = r+(a[i]-'0')+(b[i]-'0');
        s = s + (char)(r % 10+48 );
        r = r/10;
    }
    if (r>0) s = s + '1';
    reverse(s.begin(), s.end());
    return s;
}
//...........................
string hieu(string a,string b){
    int i,r=0,l=a.length();
    string s;
    b.insert(0,l-b.length(),'0');
    for (i=l-1;i>=0;i--){
        r = 10-r+(a[i]-b[i]);
        s = s + (char)(r % 10+48 );
        r = 1-r/10;
    }
    while ((s.length()!=1) && s[s.length()-1]=='0')
        s.erase(s.length()-1,1);
    reverse(s.begin(), s.end());
    return s;
}
//.....................................
string nhanNho(int a, string b)    {
    string s = "";
    int temp = 0;
    for (int i=b.length()-1; i>=0; i--)      {
        temp = a * (b[i]-'0') + temp;
        s = s + (char)(temp%10 + 48) ;
        temp = temp/10;
    }
    if (temp>0) s = s + (char)(temp+48);
    reverse(s.begin(), s.end());
    return s;
}
//.......................................
string nhan(string a, string b){     // nhan 2 so lon
    string s = "";
    int l = a.length();
    string s1[l];
    for (int i=l-1; i>=0; i--)   // nhan tung chu so cua a voi b sau do cong don vao
    {
        s1[i] = nhanNho(a[i]-'0', b);   // nhan tung so cua a voi b
        s1[i].insert(s1[i].length(), l-i-1, '0');
        s = tong(s, s1[i]);  // cong don theo cach cong so lon
    }
    return s;
}